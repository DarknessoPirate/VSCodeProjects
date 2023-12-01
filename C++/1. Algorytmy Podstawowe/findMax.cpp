#include <iostream>

template<typename T>
T findMax(const T* arr, int size)
{
    T max;
    max = arr[0];
    for(int i = 0; i < size; i++)
    {
        if(arr[i] > max)
            max = arr[i];
    }

    return max;
}


int main()
{
int numbers[] = {2, 4, 16, 8, 32, 15, 73, 24,-140 , 123};
int intsize = sizeof(numbers)/sizeof(int);
double nums[] = {0.5, 0.4, 1.7, 2.4, 3, 17.0, 18.5, 19, 4, 31, 21,-1.5, 37.5 };
int doublesize = sizeof(nums)/sizeof(double);
std::cout << "Max in Int array: " << findMax(numbers, intsize) << std::endl;
std::cout << "Max in Double array: " << findMax(nums,doublesize) << std::endl;
}