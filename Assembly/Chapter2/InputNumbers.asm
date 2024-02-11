option casemap:none

nl = 10;// ASCII for newline
maxLen = 256

.data
titleStr byte 'Listing 2-3', 0
prompt1 byte "Enter an integer between 0 and 127:", 0
fmtStr1 byte "Value in hex: %x", nl, 0
fmtStr2 byte "Inverted bits (hex): %x", nl, 0
fmtStr3 byte "After adding 1 (hex): %x", nl, 0
fmtStr4 byte "Output as signed integer: %d", nl, 0
fmtStr5 byte "After using neg instruction: %d", nl, 0

intValue sqword ?
input byte maxLen dup (?)

.code 
externdef printf:proc
externdef atoi:proc
externdef readLine:proc

;// function to return program title to c++
public getTitle
getTitle proc
lea rax, titleStr
ret
getTitle endp

public asmMain
asmMain proc
sub rsp, 56 ;// magic instruction without explanation
;// print the prompt asking to enter input
lea rcx, prompt1
call printf

lea rcx, input ;//put input variable addres in rcv
mov rdx, maxLen ;// put maxlen in rdx
call readLine ;// use readline to read the input into input variable

;// call C stdlib atoi function that converts string to int
; // use: i = atoi(str)
lea rcx, input ;// load string into rcx (microsoft ABI)
call atoi 
and rax, 0ffh ;// wipe all bits except 8 LO bits from return result
mov intValue, rax
;// Print the int value as hex using printf
lea rcx, fmtStr1 ;// load first variable into correct register
mov rdx, rax ;// load second variable into second register
call printf

;// Inverting all the bits(only lower byte) and then printing result
lea rcx, fmtStr2
mov rdx, intValue
not dl ;// invert lower byte(assume our number is 8 bits at max)
call printf

;// Invert all the bits(full register) and add 1 then printf 
;// then only keep 8 LO bits
lea rcx, fmtStr3
mov rdx, intValue
not rdx
add rdx, 1
and rdx, 0ffh ;// Only keep 8 LO bits
call printf

;// Negate the value and print as signed int, we are working with 32-bit ; integer here because c++ expects 32-bit integer in %d in format string
lea rcx, fmtStr4
mov rdx, intValue
not rdx
add rdx, 1
call printf

;// Only negate the number without adding 1 and print it
mov rdx, intValue
neg rdx
lea rcx, fmtStr5
call printf

;// Undo the effect of previous magic instruction
add rsp, 56
ret ;// returns to caller
asmMain endp
end