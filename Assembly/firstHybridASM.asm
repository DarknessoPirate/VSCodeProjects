; contains empty function to be called by C++ module firstHybrid.cpp
.CODE

option casemap:none ; MASM maps all characters to uppercase by default so we turn it off so that it doesnt map function name asmFunc() to ASMFUNC() 

public asmFunc ; public identifier enables the function to be visible outside the MASM source/object file, without it
; the asmFunc would be inaccessible to the C++ code and only accessible withing the MASM module
asmFunc PROC
; empty function just returns 
    ret
asmFunc ENDP
END

; to compile and run these source files use:
; ml64 /c firstHybridASM.asm // creates ASM obj file
; -----------   /c option means compile only and does not attempt to run the linker 
; cl firstHybridCPP.cpp firstHybridASM.obj // link cpp with ASM obj file
; ----------- cl command runs the MSVC compiler on cpp file and links in the assembled .obj code creating the executable file
; firstHybridCPP.exe // run created exe file