#include <iostream>

int main()
{

    int** a = new int*[2];
    int* b =new int[2*2];
    a[0] = b ;
    a[1] = b + 4;  // + 4 bytes
    a[0][0] = 5;
    a[0][1] = 10;
    a[1][0] = 15;
    a[1][1] = 20;
    std::cout << a[1][0];
}