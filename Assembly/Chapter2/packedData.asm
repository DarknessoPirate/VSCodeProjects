option casemap:none

NULL = 0
nl = 10 ; ascii newline code
maxLen = 256

.const ; const holds values for read-only constants
ttlStr byte 'Packed data', 0
moPrompt byte 'Enter current month: ', 0
dayPrompt byte 'Enter current day: ', 0
yearPrompt byte 'Enter current year(last 2 digits): ', 0

packed byte 'Packed date is %04x', nl, 0
theDate byte 'The date is %02d/%02d/%02d', nl, 0

badDayStr byte 'Bad day value was entered(expected 1-31)',nl,0
badMonthStr byte 'Bad month value was entered(expected 1-12)',nl,0
badYearStr byte 'Bad year value was entered(expected 00-99)',nl,0

.data
month byte ?
day byte ?
year byte ?
date word ?

input byte maxLen dup (?)

.code
externdef printf:proc
externdef readLine:proc
externdef atoi:proc

public getTitle ; return title to c++ program
getTitle proc
    lea rax,ttlStr
    ret
getTitle endp

;int readNum(char* prompt)

readNum proc
    sub rsp,56 ; must align stack properly before we can call any C/C++ functions
    call printf ; prompt message will be passed to this procedure in RCX and then printf inside will use it
    lea rcx, input
    mov rdx, maxLen
    call readLine

    cmp rax, NULL ; checking for a bad input string
    je badInput ; jump if equal 

    ; if input is good we should be here now
    ; now trying to convert string to int
    lea rcx, input ; load pointer to string into rcx (atoi expects the argument in rcx)
    call atoi ; convert to int

    badInput:
        add rsp,56 ; return stack alignment to how it was before
        ret
    readNum endp

public asmMain
asmMain proc
    sub rsp,56 ; align stack to use c/c++ functions
    
    ; read month
    lea rcx, moPrompt ; passing the month prompt to readNum, it is then passed to printf inside
    call readNum ; it calls readline inside and then readline returns result to rax

    cmp rax, 1 ; check (value in rax) - 1 (sets appropriate flags)
    jl badMonth ; jump if value in rax < 1
    cmp rax, 12  ; check (value in rax) - 12 (sets flags)
    jg badMonth ; jump if value in rax > 12

    ;if month was good we should be here by now
    mov month, al ; save the al(lower byte) data in month variable( byte sized register )

    ; read day
    lea rcx, dayPrompt
    call readNum
    ; checking if day in range 1-31
    cmp rax, 1
    jl badDay
    cmp rax, 31
    jg badDay

    ; if day is good we should be here now
    mov day, al ; save al(lower byte) data in day variable
    
    ;read the year
    lea rcx, yearPrompt
    call readNum
    ; verify the year is in range 0-99
    cmp rax, 0
    jl badYear
    cmp rax, 99
    jg badYear

    mov year, al ; save year data in year variable

    ; pack variables
    movzx ax, month ; move with zero extend
    shl ax, 5 ; shift ax(word) 5 bits to the left to make space for day data
    or al, day ; place the day data using or instruction to not overwrite the rest of data
    shl ax, 7 ; shift 7 bits to the left to make space for year data
    or al, year ; place year data using or instruction, to not erase the rest of bits
    mov date, ax ; place the resulting packed data in date

    lea rcx, packed
    movzx rdx, date ; move the value to rdx and zero-extend it to be the same size as rdx
    call printf

    ; unpack the date and print it
    lea rcx, theDate ; load the print statement address to printf
    movzx rdx, date ; load packed date into rdx and zero-extend it
    mov r9, rdx
    and r9, 7fh ; keep LO 7 bits | 7fh = 0111_1111b
    shr rdx, 7 ; shift the data to the right to get rid of year data
    mov r8, rdx ; load day data into r8
    and r8, 1fh ; Keep only 5 LO bits | 1fh = 0001_1111
    shr rdx, 5 ; shift rdx 5 to the right to get rid of day data and get month data ready

    ; the rdx has only month data with zeros extended so the registers(rcx,rdx,r8,r9)
    ; are correctly loaded with needed data so we can use printf
    call printf 
    jmp allDone
    
    ; bad data labels
badDay: 
    lea rcx, badDayStr
    call printf
    jmp allDone

badMonth:
    lea rcx, badMonthStr
    call printf
    jmp allDone

badYear:
    lea rcx, badYearStr
    call printf
    jmp allDone

allDone:
    add rsp, 56 ; align stack
    ret ; return to caller
asmMain endp
end
