#include <iostream>

struct Node{
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        next = NULL;
    }

};

class LinkedListSentinelNode
{
    Node* headSentinel;
    Node* tailSentinel;
    int size;

public:

LinkedListSentinelNode()
{
    headSentinel = new Node(0);
    tailSentinel = new Node(0);
    headSentinel->next = tailSentinel;
}

void insert_front(int value)
{
    Node* new_node = new Node(value);

    new_node->next = headSentinel->next;

    headSentinel->next = new_node;
    std::cout << "Added " << value << " at the front of the list" << std::endl;
    size++;
}

Node* find(int data){
    Node* ptr = headSentinel;
    int i = 0;
    while(ptr->next != tailSentinel){
        ptr = ptr->next;
        if(ptr->data == data){
            std::cout << "Item found!\n";
            return ptr;
        }
    }
    std::cout << "Item not found!\n";
    return 0;
}

void insert_last(int value)
{
    Node* new_node = new Node(value);
    Node* ptr = headSentinel->next;
    while(ptr->next != tailSentinel)
        ptr = ptr->next;

    new_node->next = ptr->next;
    ptr->next = new_node;

    std::cout << "Added " << value << " at the end of the list" << std::endl;
    size++;
}

void insert_at_index(int value, int index)
{
    if(headSentinel->next == tailSentinel)
    {
        std::cout << "The list is empty";
        return;
    }

    Node* new_node = new Node(value);
    Node* ptr = headSentinel;

    for(int i = 0; i < index-1; i++)
    {
        if(ptr->next == tailSentinel)
        {
            if(i == index - 2)
            {
                break;
            }
            else
            {
                std::cout << "Index out of range";
                return;
            }
        }
        ptr=ptr->next;
    }

    new_node->next = ptr->next;
    ptr->next = new_node;

    std::cout << "Added " << value << " at index "<< index << std::endl;
    size++;
}

void delete_first()
{
    if(headSentinel->next ==tailSentinel)
    {
        std::cout << "There's nothing to delete. List is empty." << std::endl;
        return;
    }

    Node* temp = headSentinel->next;
    headSentinel->next = headSentinel->next->next;

    std::cout << "Deleted first element: " << temp->data << std::endl;
    delete temp;
    size--;
}

void delete_last()
{   
    if(headSentinel->next == tailSentinel){
        std::cout << "The list is empty :( ";
        return;
    }

    Node* ptr = headSentinel->next;
    Node* last; 

    while(ptr->next != tailSentinel)
    {
        last = ptr;
        ptr = ptr->next;
    }
    last->next = ptr->next;

    std::cout << "Deleted last element: " << ptr->data << std::endl;
    delete ptr;
    size--;
}

void delete_at_index(int index)
{
    Node* ptr = headSentinel;
    Node* last;
    for(int i = 0; i < index-1; i++)
    {
        if(ptr->next == tailSentinel)
        {
            if(i == index - 2)
            {
                break;
            }
            else
            {
                std::cout << "Index out of range";
                return;
            }
        }
        last = ptr;
        ptr=ptr->next;
    }

    last->next = ptr->next;

    std::cout << "Deleted " << ptr->data << " at index " << index << std::endl;
    delete ptr;
    size--;
}

void displayList()
{
    Node* ptr = headSentinel->next;
    std::cout << "The list is:\n"; 
    std::cout << "head" << "->";
    while(ptr!=tailSentinel)
    {
        std::cout << ptr->data<< "->"; ;
        ptr=ptr->next;
        if(ptr == tailSentinel)
            std::cout << "tail";
    }
}


};



int main()
{
    LinkedListSentinelNode list;
    list.insert_front(2);
    list.insert_front(2);
    list.insert_front(2);
    list.insert_front(1);
    list.insert_at_index(3,3);
    list.insert_last(7);
    list.insert_last(15);
    list.delete_first();
    list.delete_last();
    list.delete_at_index(3);
    Node* n1 = list.find(7);
    Node* n2 = list.find(9);
    list.displayList();




}