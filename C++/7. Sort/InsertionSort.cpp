#include <iostream>

template<typename T>
void insertionSort(T* arr, int size){
    T temp;
    int j;
    for(int i = 1; i < size; i++){
        temp = arr[i];
        j = i-1;

        while(j>=0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j -= 1;
        }
        arr[j+1] = temp;
    }
}

template<typename T>
void printArray(T* arr, int size)
{
    for(int i = 0; i < size; i++){
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
int main()
{
double numbers[] = {17.5, 13.2, 12.7, 1.3, 5.2, 7, 8.1, 9};
int nums[] = {7,2, 5, 9, 13, 2, 27, 3, 19, 4};
insertionSort(numbers, 8);
insertionSort(nums, 10);
printArray(numbers,8);
printArray(nums,10);




}