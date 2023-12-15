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

Node* insertItem(Node* root,  int new_data)
{
    Node* new_node = new Node(new_data);

    if(root==NULL){
        return createNewList(root,new_data);
    }
    
    new_node->next = root->next;
    root->next = new_node;

    return root;
}
    
void printList(Node* last)
{
// Checking for empty list
    
    if(last==NULL) 
    {
        std::cout << "List is empty" << std::endl;
        return;
    }
    Node* ptr = last; // pointer used to move through the list
    
// Traverse the list until we reach the first element again
    do{ 
        std::cout << ptr->data << "->";
        ptr = ptr->next;
        
    }while(ptr != last);  
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
    }while(temp != root);
    std::cout << "Couldn't find node";
    return NULL;
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
        std::cout << "\nThe node with data: " << key << " has been deleted" << std::endl;

    }

}



int main()
{
    Node* root = NULL;
    root = createNewList(root, 7);
    root = insertItem(root, 8);
    root = insertItem(root, 1);
    root = insertItem(root,23);
    printList(root);
    deleteNode(&root,23);
    printList(root);
    Node* foundData = find(root, 8);
    std::cout << "\nfound data:"<<foundData->data;

}