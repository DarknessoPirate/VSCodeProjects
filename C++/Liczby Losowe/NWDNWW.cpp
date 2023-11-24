#include <iostream>

int NWD(int a, int b)
{
    int temp;

    while(b != 0)
    {
        temp = b;
        b = a%b;
        a = temp;
    }
    return a;
}

int NWW(int a, int b)
{
    int nww = (a*b)/NWD(a,b);

    return nww;
}

int main()
{
    std::cout << NWD(7,77) << std::endl;
    std::cout << NWW(7,120) << std::endl;


}