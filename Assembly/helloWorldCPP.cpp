#include <stdio.h>

extern "C"
{
    void asmFunc(void);
}

int main(void){
    // we need to call printf() in the c program at least once to be able to call it from assembly
    printf("Calling asmFunc:\n");
    asmFunc();
    printf("Returned from asmFunc\n");
}

// to link it with helloWorld.cpp use ml64 helloWorld.asm - to create .obj of assembly file
// link .obj file to .cpp file with cl helloWorldCPP.cpp helloWorld.obj
// run the resulting .exe file named helloWorldCPP.exe