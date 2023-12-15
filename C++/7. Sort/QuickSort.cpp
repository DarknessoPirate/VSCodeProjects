#include <iostream>
#include <chrono>
template<typename T>
void swap(T& a, T& b)
{
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
int partition(T arr[], int start, int end)
{
 
    T pivot = arr[start];
 
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (arr[i] <= pivot) {
            i++;
        }
 
        while (arr[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
 
    return pivotIndex;
}

template<typename T>
void quickSort(T* arr, int start, int end)
{
    if(start >= end)
        return;

    int p = partition(arr, start, end);
    quickSort(arr, start, p-1);
    quickSort(arr, p+1, end);
}

template<typename T>
void printArray(T *arr, int size)
{
    for(int i = 0; i<size; i++){
        std::cout << arr[i] << " " ; 
    }
}

int main()
{
int numbers[100000];
for(int i = 0; i<100000; i++){
    numbers[i] = rand() % 100000;
}
auto start = std::chrono::system_clock::now();
quickSort(numbers,0,99999);
auto end = std::chrono::system_clock::now();
auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken to sort by quick sort: " << result.count() << " miliseconds\n";

// printArray(numbers, 1000);
}