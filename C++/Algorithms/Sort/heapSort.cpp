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
void heapify(T arr[], int size, int i )
{
int largest = i;
int leftChild = 2*i+1;
int rightChild = 2*i+2;

// checking whether children are holding bigger value than given root
if(leftChild < size && arr[leftChild] > arr[largest])
    largest = leftChild;

if(rightChild < size && arr[rightChild] > arr[largest])
    largest = rightChild;

if(largest != i){
    swap(arr[i], arr[largest]);
    heapify(arr,size,largest);

}


}

template<typename T>
void heapSort(T arr[], int size){
// building max heap
    for(int i = size/2 - 1 ; i >= 0; i--){
        heapify(arr,size,i);
    }
//sorting
    for(int i = size - 1; i >= 0; i--){
        swap(arr[0],arr[i]);
        heapify(arr,i,0);
    }

}

template<typename T>
void printArray(T arr[],int size)
{
    for(int i = 0; i<size; i++)
        std::cout << arr[i] << "  ";


}

int main()
{


double arr[10] = {7.5,7.8,5.4,2.0,9.3,3.1,8.2,4.9,6.4,2.7};
int arrsize = sizeof(arr)/sizeof(arr[0]);

std::chrono::time_point start = std::chrono::high_resolution_clock::now();
heapSort(arr,arrsize);
std::chrono::time_point stop = std::chrono::high_resolution_clock::now();

auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

printArray(arr,arrsize);
std::cout << "\n" << duration.count();

}