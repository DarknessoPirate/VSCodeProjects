.code

myProcedure proc
    ret
myProcedure endp

; here starts the main procedure
main proc

    call myProcedure ; call procedure
    ret ; return to caller

main endp

end

; you can compile it using: ml64 firstProcedure.asm /link /subsystem:console /entry:main
; and run it by opening firstProcedure.exe or typing firstProcedure in cmd