#include <iostream>
#include <chrono>

template<typename T>
void merge(T arr[],int start, int mid, int end) // used to merge 2 subarrays into one array
{
    int l1 = mid - start + 1; // last index of first subarray
    int l2 = end - mid; // last index of second array

    // Creating 2 subarrays 
    T L[l1]; 
    T R[l2]; 
    // filling subarrays with the corresponding values
    for(int i = 0; i<l1; i++)
    {
        L[i] = arr[start + i];
    }
        

    for(int j = 0; j<l2; j++)
    {
        R[j] = arr[mid + j + 1];
    }
        

    int i, j, k; // used to store current index values
    // set up to first positions
    i = 0;
    j = 0;
    // set up to the given starting index of "main" array
    k = start;

    // Checking whether we reached the end of any of the subarrays
    while(i < l1 && j < l2){
        if(L[i] <= R[j]){
            arr[k] = L[i]; // if the value in array L is bigger than the current value of R we add it first
            i++; // move the index and check again
        }
        else{
            arr[k] = R[j]; // if the R holds bigger value we add it first instead
            j++; // move the index and check again
        }
        k++; // element added - move the main array index forward 
    }

    // When one we reached end of one array we have to add the rest 
    // of the elements remaining in any of the arrays to the end of the main array
    // Array L
    while(i<l1){
        arr[k] = L[i];
        k++; // move both indexes 
        i++;
    }

    // Array R
    while(j<l2){
        arr[k] = R[j];
        k++;
        j++;
    }
}

template<typename T>
void mergeSort(T arr[], int start, int end)
{
    if(start < end){
    
    int m = start + (end - start) / 2;
    
    mergeSort(arr, start, m);
    mergeSort(arr, m+1, end);
    merge(arr, start, m , end);
}


}

    
template<typename T>
void printArray(T *arr, int size)
{
    for(int i = 0; i<size; i++)
    {
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
mergeSort(numbers,0,99999);
auto end = std::chrono::system_clock::now();
auto result = std::chrono::duration_cast<std::chrono::milliseconds>(end - start);
std::cout << "Time taken to sort by merge sort: " << result.count() << " miliseconds\n";

// printArray(numbers,1000);
}