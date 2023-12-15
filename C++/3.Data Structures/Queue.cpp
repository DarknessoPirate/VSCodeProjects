#include <iostream>

class Queue
{
    int front;
    int rear;
    int size; 
    unsigned capacity; 
    int* data;

public:

Queue(unsigned queueSize)
{
    this->data = new int[queueSize]; // creating array of given size
    this->capacity = queueSize; // initializing variables
    this->size = 0;
    this->front = 0;
    this->rear = this->capacity - 1; // rear is the last element
}

bool isFull()
{
    return (this->size == this->capacity);
}

bool isEmpty()
{
    return (this->size == 0);
}

int find(int data){
    if(isEmpty()){
        std::cout << "Queue is empty";
        return INT_MIN;
    }
    for(int i = 0; i < size; i++){
        if(this->data[i] == data){
            std::cout << "Element found at index " << i << std::endl;
            return i;
        }
    }
    std::cout << "Couldn't find element\n";
    return INT_MIN;
}

void enqueue(int item) // adding elements to the queue
{
    if(isFull())
    {
        std::cout << "Queue is full! Returning..." << std::endl;
        return; // do nothing if queue is full
    }


    // modulo makes sure that the rear value doesnt go out of bounds of the array
    this->rear = (this->rear + 1) % this->capacity; // now the rear is at the first index
    this->data[this->rear] = item; 

    this->size++; // incrementing the size

    std::cout << "Item " << item << " added to the queue!" << std::endl;
}

int dequeue()
{
    if(isEmpty())
    {
        std::cout << "Queue is empty! Returning..." << std::endl;
        return INT_MIN; // return INT_MIN if queue is empty 
    }

    int item = this->data[this->front]; // storing the item in temp variable

    // modulo again makes sure that the front value doesnt go out of bounds of the array
    this->front = (this->front + 1) % this->capacity; // now the front is at the second index
    this->size--; // decrementing the size

    return item; // returning the item
}

int Front()  // returns item at the front of the queue
{
    if(isEmpty())
    {
        std::cout << "The queue is empty! There is no front :( \n";
        return INT_MIN;
    }

    return this->data[this->front];
}

int Rear()  // return the last item in the queue
{
    if(isEmpty())
    {
        std::cout << "The queue is empty! There is no rear :( \n";
        return INT_MIN;
    }

    return this->data[this->rear];
}

};




int main ()
{
Queue q(10);
// Checking the safety mechanisms
std::cout << q.dequeue() << std::endl;
std::cout << q.Front() << std::endl;
std::cout << q.Rear() << std::endl;

// Checking functionality
q.enqueue(1);
q.enqueue(7);
q.enqueue(9);
int b = q.find(9);
std::cout << "Front item: "<<  q.Front() << std::endl;
std::cout << "Last item: "<< q.Rear() << std::endl;
std::cout << "Dequeued: "<<q.dequeue() << std::endl;

// Checking again after the queue state has changed
std::cout << "Front item: "<<  q.Front() << std::endl;
std::cout << "Last item: "<< q.Rear() << std::endl;


// Checking overflow safety mechanism
/*
for(int i = 0; i < 11; i++)
{
    q.enqueue(i);
}
*/
}