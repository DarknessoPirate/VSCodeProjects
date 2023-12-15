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
int numbers[100000];
for(int i = 0; i<100000; i++){
    numbers[i] = rand() % 100000;
}
auto start = std::chrono::system_clock::now();
heapSort(numbers,100000);
auto end = std::chrono::system_clock::now();
auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken to sort by heap sort: " << result.count() << " miliseconds\n";

// printArray(numbers,1000);
}