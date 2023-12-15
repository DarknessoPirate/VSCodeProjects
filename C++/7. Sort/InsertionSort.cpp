#include <iostream>
#include <chrono>

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
int numbers[100000];
for(int i = 0; i<100000; i++){
    numbers[i] = rand() % 100000;
}
auto start = std::chrono::system_clock::now();
insertionSort(numbers,100000);
auto end = std::chrono::system_clock::now();
auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken to sort by insertion sort: " << result.count() << " miliseconds\n";

// printArray(numbers, 1000);
}