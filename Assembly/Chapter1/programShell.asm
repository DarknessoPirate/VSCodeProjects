; The ".code" directive tells MASM that the statements following
; this directive go in the section of memory reserved for machine
; instructions (code).

.code
; Here is the "main" function. (This example assumes that the
; assembly language program is a stand-alone program with its
; own main function.)
main PROC
; machine instructions go here
    ret;

main ENDP

END

; The END directive marks the end of the source file.

; to run: ml64 programShell.asm /link /subsystem:console /entry:main
; this creates exe file that you can then run
; This command tells MASM to assemble the programShell.asm program
; to an executable file, link the result to produce a console application
; and begin execution at the label main in the assembly language source file