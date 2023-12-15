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

Node* find(Node* root,int data){
    if(root == NULL){
        return NULL;
    }
    Node* temp = root;
    do{
        if(temp->data == data){
            return temp;
        }
        temp = temp->next;
    }while(temp != NULL);
    std::cout << "Couldnt find node\n";
    return NULL;
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

void removeLastNode(Node** root)
{
    if(*root==NULL)
        return;

    if((*root)->next==NULL)
    {
        delete *root;
        return;
    }

    Node* second_last = *root; 
    while(second_last->next->next != NULL) // iterate through the list until the pointer is second last node of the list
    {
        second_last = second_last->next;
    }
    delete (second_last->next); // delete the last node
    second_last->next = NULL; // change next ptr to null
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
    removeLastNode(&head);
    displayList(head);
    Node* foundData = find(head, 10);
    std::cout << "Found data: "<<foundData->data;

}