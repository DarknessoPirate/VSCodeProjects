#include <iostream>

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

int numbers[] = {0,17,12,4,7,15,3,20};
double nums[] = {0.5, 0.3, 1.5, 1.2, 33.2, 37.5, 31.0};
std::cout << "Int arr before bubble sort:\n";
print_array(numbers,8);
bubbleSort(numbers,8);
std::cout << "Int arr after bubble sort:\n";
print_array(numbers,8);

std::cout << "Double arr before bubble sort:\n";
print_array(nums,7);
bubbleSort(nums,7);
std::cout << "Double arr after bubble sort:\n";
print_array(nums,7);
}

