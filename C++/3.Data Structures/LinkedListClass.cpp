#include <iostream> 


struct Node
{
    int data; 
    Node *next;
    Node(int a)
    {
        data = a;
        next = NULL;
    }
};

class LinkedList
{
Node *head; // head reference
int size; 

public:
LinkedList() // constructor
{
    head=NULL;
    size = 0;
}

void push(int data)  // insert at the front
{
    // Creating a new node
    Node* new_node = new Node(data);

    new_node->next = this->head;   // next reference to the previous head
    this->head = new_node;  // head points to the new node

    size++;  // incrementing size after adding a new node
}

void insertAfter(int data, int position)
{
    Node** headref = &this->head; // creating a reference to the head of the list

    Node* new_node = new Node(data);  // creating a new node
    new_node->next = NULL;

    // checking whether the position is valid
    if(position < 0 || position > size+1)
        std::cout << "Invalid position" << std::endl;
    

    // looping through the list to find the correct place to insert
    while(position--)
    {
        headref = &((*headref)->next); // moving the reference forward

           if(position == 0)
        {
            new_node->next = *headref;  // inserting the new node 
            *headref = new_node;  // switching the old pointer to the newly inserted node

            // checking whether the inserted node is the last node, if so we set it as the tail
        }
    }
   size++; // increasing size 
}

void append(int data)
{
    Node *new_node = new Node(data); // creating a new node
    if(this->head == NULL)
    {
        this->head = new_node;
        return;
    }
    Node *last = this->head;
    while(last->next != NULL)
    {
        last = last->next;
    }
    last->next = new_node;

}
// delete the head of the list
void pop() 
{
    Node* temp = this->head;  // storing the head of the list
    this->head = this->head->next;  // changing the head reference to the next element
    delete temp;  // deleting the previous head of the list
}

Node* find(int data){
    if(head == NULL){
        return NULL;
    }
    Node* temp = head;
    do{
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }while(temp != NULL);
    std::cout << "Couldnt find node\n";
    return NULL;
}

void deleteNode(int position)
{
    Node** headref = &this->head; // storing head address   
    Node* temp = NULL;  // temporary variable to store the node to be deleted

    // checking whether the position is valid
    if(position < 0 || position > size+1)
        std::cout << "Invalid position" << std::endl;

    // Looping through the list to find the correct position to delete
    while(position--)
    {
        headref = &((*headref)->next);
    }

    temp = *headref;  // storing the node to be deleted
    *headref = (*headref)->next;  // changing the node reference to the next element
    delete temp;  // deleting the previous head of the list


}

void removeLastNode()
{
    if(head==NULL)
        return;

    if(head->next==NULL)
    {
        delete this->head;
        this->head = NULL;
        return;
    }

    Node* second_last = this->head; 
    while(second_last->next->next != NULL) // iterate through the list until the pointer is second last node of the list
    {
        second_last = second_last->next;
    }
    delete (second_last->next); // delete the last node
    second_last->next = NULL; // change next ptr to null
}

void printList()
{
    while(this->head != NULL)
    {
        std::cout << this->head->data << " ";
        this->head = this->head->next;
    }

}



};

int main()
{
LinkedList list;
list.push(10);
list.push(20);
list.insertAfter(30, 1);
list.printList();
list.append(40);
list.append(50);
list.removeLastNode();
Node* foundData = list.find(40);
list.printList();
std::cout << "\nFound data:" <<foundData->data;

return 0;
}