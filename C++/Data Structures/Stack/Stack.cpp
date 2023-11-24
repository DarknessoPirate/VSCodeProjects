#include <iostream>

#define MAX 100

class Stack
{
    int top;

    public: 
    int array[MAX];
    Stack(){top=-1;}

    bool push(int x)
    {
        if(top>= MAX-1)
        {
            std::cout << "Overflow!\n";
            return false;
        }

        else
        {   
            array[++top] = x;
            std::cout << x << " pushed to the stack\n";
            return true;
        }
    }

    int pop()
    {
        // check if the stack is empty
        if(top<0)
        {
            std::cout << "Underflow!\n";
            return -1; 
        }

        return array[top--];  // returning the value, decrementing the top variable
    }

    int peek()
    {
        if(top<0)
        {
            std::cout << "Stack is empty!\n";
            return -1; 
        }

        return array[top];
    }

    bool isEmpty()
    {
        std::cout << "Stack is empty\n";
        return top<0;
    }
};

int main()
{
    Stack testStack;
    testStack.isEmpty(); // checking if the implemented checks are working
    testStack.peek();
    testStack.pop(); // checking if underflow check is working
    testStack.push(1);
    testStack.push(2);
    std::cout << "popped value: " <<testStack.pop() << std::endl;
    std::cout << "value at the top: " << testStack.peek() << std::endl;

/*
    for(int i=0; i<100; i++)  // checking if overflow check is working
    {
        testStack.push(i);
    }
*/

}