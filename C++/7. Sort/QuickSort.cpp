#include <iostream>

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

int main()
{
    double numbers[] = {11.5, 2.3, 4.7, 3, 5.2, 17.3, 12.1, 20, 1, 0, 17,  5.3};

    std::cout << "Before quickSort:\n";
      for(int i = 0; i < 12; i++)
        std::cout << numbers[i] << ",";

    std::cout << std::endl;
    quickSort(numbers, 0, 11);

    std::cout << "After quickSort:\n";
      for(int i = 0; i < 12; i++)
        std::cout << numbers[i] << ",";

}