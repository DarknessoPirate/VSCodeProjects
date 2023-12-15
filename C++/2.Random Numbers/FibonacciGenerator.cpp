#include <iostream>

unsigned int fib(int i, int m) // wypisuje liczbe i fibonacciego w zakresie do m-1
{
    unsigned int a = 1, b = 1, temp = 0;

    for(int k = 0; k<i; k++){
        b = temp;    
        temp = (temp+a)%m;
        a = b;
    }
    return temp;
}

void fibGen(int i, int m)
{
    for(int j = 0; j<i;j++){
        std::cout<<fib(j,m) << " ";
    }


}
int main()
{
fibGen(100,173);


}