#include <iostream>

struct Node{
    int data;
    Node* next;
    Node* prev;
    Node(int new_data)
    {
        data = new_data;
        next = NULL;
        prev = NULL;
    }

};

void insertFront(Node** head, int data)
{
    Node* new_node = new Node(data);
    new_node->next = (*head); 

    if((*head) != NULL)
        (*head)->prev = new_node;
    
    (*head) = new_node;
}

void insertAfter(Node* prev_node, int data)
{
    Node* new_node = new Node(data);

    if(prev_node == NULL)
    {
        std::cout << "The given node is NULL" << std::endl;
        return;
    }
        
    new_node->next = prev_node->next;  // passing the previous node next pointer to the new node
    prev_node->next = new_node;    // setting the pointers
    new_node->prev = prev_node;

    if(new_node->next != NULL)
        new_node->next->prev = new_node;
}

void insertAtEnd(Node** head, int data)
{
    Node* new_node = new Node(data);
    Node* last = *head;

    if(*head == NULL)
    {
        *head = new_node;
        return;
    }

    // Traversing through the array until the end
    while(last->next != NULL)
        last = last->next;
    
    last->next = new_node;
    new_node->prev = last; 
    return;
}

void displayList(Node* head)
{
    Node* temp = head;
    while(temp != NULL)
    {
        std::cout << temp->data << " ";
        temp = temp->next;
    }

    if(temp == NULL);
        std::cout << "NULL" << std::endl;
}

int main()
{
    Node* head = NULL;
    insertFront(&head, 5);
    displayList(head);
    insertAtEnd(&head,10);
    displayList(head);
    insertAfter(head->next,7);
    displayList(head);

}