option casemap:none
nl = 10 ; ascii for newline

.data
i qword 1
j qword 123
k qword 456789

titleStr byte 'Listing 2-1', 0
fmtStrI byte "i=%d, converted to hex=%x", nl, 0
fmtStrJ byte "j=%d, converted to hex=%x", nl, 0
fmtStrK byte "k=%d, converted to hex=%x", nl, 0

.code 
externdef printf:proc

public getTitle
getTitle proc
; load address of "titleStr into RAX(holds return result)"
; and return back to caller
lea rax, titleStr
ret
getTitle endp

public asmMain ; the main entry point
asmMain proc
sub rsp, 56 
;printf("i=%d, converted to hex=%x\n", i, i)  call printf to print the value
lea rcx, fmtStrI ; move the variables into corresponding registers 
mov rdx, i ; appropriate to printf microsoft ABI
mov r8, rdx 
call printf

; doing the same thing again but for j
lea rcx, fmtStrJ
mov rdx, j
mov r8, rdx
call printf

; doing the same thing for k
lea rcx, fmtStrK
mov rdx, k
mov r8, rdx
call printf

add rsp, 56 ; returning rsp to the state it was before
ret ; return control to caller

asmMain endp
end