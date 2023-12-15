#include <iostream>
#include <random>
#include <chrono>

template<typename T>
void bubbleSort(T* arr, int size){
    bool just_swapped = false;

    for(int i = 0; i<size-1; i++){
        for(int j = 0; j < size-1; j++){
            if(arr[j] > arr[j+1]){
                T temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                just_swapped = true;
            }
        }
        if(!just_swapped)
            return;
        // optimization
    }
}

template<typename D>
void print_array(D* array, int size)
{
    for(int i = 0; i < size; i++)
    {
        std::cout << array[i] << " ";
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
bubbleSort(numbers,100000);
auto end = std::chrono::system_clock::now();
auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken to sort by bubble sort: " << result.count() << " miliseconds";

// print_array(numbers, 1000);

}

