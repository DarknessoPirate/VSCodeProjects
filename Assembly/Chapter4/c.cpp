#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// extern "C" namespace prevents "name mangling" by the C++
// compiler
extern "C"{
    void asmMain();
    char* getTitle(void);

//returns a pointer to a string of character from asm code that specifies the
// title of that program

int readLine(char *dest, int maxLen)
{
 // fgets returns NULL if there was an error, else
 // it returns a pointer to the string data read (which
 // will be the value of the dest pointer).
 char *result = fgets(dest, maxLen, stdin);
 if(result != NULL)
 {
 // Wipe out the newline character at the
 // end of the string:
 int len = strlen(result);
 if(len > 0)
 {
 dest[len - 1] = 0;
 }
 return len;
 } 
 return -1; // If there was an error
}
}

int main(void)
{
 // Get the assembly language program's title:
 try
 {
 char *title = getTitle();
 
 printf("Calling %s:\n", title);
 asmMain();
 printf("%s terminated\n", title);
 }
 catch(...)
 {
 printf
 ( 
 "Exception occurred during program execution\n"
 "Abnormal program termination.\n"
 );
 }
}