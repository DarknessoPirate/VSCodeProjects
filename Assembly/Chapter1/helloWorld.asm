option casemap:none

.data
    fmtStr byte "Hello, World!", 10, 0

.code
; external declaration so that masm knows about the printf
    externdef printf:proc

    public asmFunc
    asmFunc proc
    ; magic instruction, will be explained in later projects
    sub rsp, 56
    lea rcx, fmtStr
    call printf
    ; another magic instruction that undoes the thing the one before it did
    add rsp, 56
    ret
    asmFunc endp
end