
def bubbleSort(arr):
    for i in range(len(arr)):
        for j in range(len(arr)-1):
            if(arr[j] > arr[j+1]):
                arr[j], arr[j+1] = arr[j+1],arr[j]


def insertionSort(arr):

    for i in range(1,len(arr)):
        j = i -1
        key = arr[i]

        while(j>= 0 and key < arr[j]):
            arr[j+1] = arr[j]
            j -= 1

        arr[j+1] = key

def partition(array, start, end):
  
  pivot = array[end]
  i = start - 1


  for j in range(start, end):
    if array[j] <= pivot:

      i = i + 1


      (array[i], array[j]) = (array[j], array[i])

  (array[i + 1], array[end]) = (array[end], array[i + 1])
  return i + 1


def quickSort(array, start, end):
  if start < end:
    pi = partition(array, start, end)
    quickSort(array, start, pi - 1)
    quickSort(array, pi + 1, end)


data = [81, 17, 22, 11, 10, 9, 6,7,8,6,3,0]
data1 = [81, 17, 22, 11, 10, 9, 6,7,8,6,3,0]
data2 = [81, 17, 22, 11, 10, 9, 6,7,8,6,3,0]
#print("Unsorted Array")
#print(data)

#size = len(data)

#quickSort(data, 0, size - 1)
#bubbleSort(data1)
#insertionSort(data2)

#print('QuickSort:',data)
#print('BubbleSort:',data1)
#print('InsertionSort:',data2)
# zakomentowane bo importuje zad38 do zad 40 zeby nie wyswietlal sie output