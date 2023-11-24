#include <iostream>

struct Node
{
    int data;
    Node* next;

    Node(int new_data)
    {
        data = new_data;
        next = NULL;
    }
};

Node* createNewList(Node* last, int new_data)
{
    if(last != NULL)
    {
        std::cout << "The list already exists";
        return last;
    }
        

    last = new Node(new_data);
    last->next = last;

    return last;
}

Node* insertAtBegin(Node* last, int new_data)
{
    // if the list is empty create a new list and return the address
    if(last==NULL)
        return createNewList(last, new_data);

    Node* new_node = new Node(new_data);
    new_node->next = last->next;
    last->next = new_node;

    return last;
}

Node* insertAtEnd(Node* last, int new_data)
{
    if(last==NULL)
        return createNewList(last, new_data);

    Node* new_node = new Node(new_data);
    new_node->next = last->next;
    last->next = new_node;
    last = new_node;

    return last;
}

Node* insertAfterItem(Node*last, int new_data, int after_data)
{
    if(last==NULL)
        return NULL;

    
    Node* temp_ptr = last->next; // stores the location of the first element in the list

    do
    {
        if(temp_ptr->data == after_data)
        {
            Node* new_node = new Node(new_data);
            new_node->next = temp_ptr->next;
            temp_ptr->next = new_node;

            return last;
        }

        temp_ptr = temp_ptr->next;
    } while (temp_ptr != last->next);

    // when item isn't found
    std::cout << "Node with data" << after_data << "wasn't found in the list" << std::endl;
    return last;
}
    
void printList(Node* last)
{
// Checking for empty list
    
    if(last==NULL) 
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* ptr = last->next; // pointer used to move through the list
    
// Traverse the list until we reach the first element again
    do{ 
        std::cout << ptr->data << "->";
        ptr = ptr->next;
        
    }while(ptr != last->next);  
    if(ptr==last->next)
        std::cout << ptr->data << std::endl;
    
}

void deleteNode(Node** head, int key)
{
    if(*head == NULL)
        return;

// If it's the only element remove it and set ptr to null
    if((*head)->data == key && (*head)->next==*head)
    {
        delete *head;
        *head = NULL;
        return;
    }

    Node** last = head;
    Node* temp;
// If the element we have to delete is the last element, we find the second last element and pass the pointers data to him
    if((*last)->data == key)
    {
        while((*last)->next != *head)
            *last = (*last)->next;

        (*last)->next = (*head)->next;
        delete head;  // deleting the last
        *head = *last;
        return;
    }

    while((*last)->next != *head && (*last)->next->data != key)
        *last = (*last)->next;

// Found the node, deleting and switching pointers
    if((*last)->next->data == key)
    {
        temp = (*last)->next;
        (*last)->next = (*last)->next->next;
        delete temp;
        std::cout << "The node with data: " << key << " has been deleted" << std::endl;

    }

}



int main()
{
    Node* last = NULL;
    last = createNewList(last, 7);
    deleteNode(&last,7);
    printList(last);
    last = insertAtBegin(last, 5);
    last = insertAtBegin(last, 4);
    last = insertAtEnd(last, 2);
    last = insertAtEnd(last, 1);
    last = insertAfterItem(last, 2,2 );
    printList(last);
}