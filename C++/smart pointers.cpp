#include <iostream>
#include <memory>

int main()
{
std::unique_ptr<int> pointerName(new int(15));
std::cout << *pointerName;
}