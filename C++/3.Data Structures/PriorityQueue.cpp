#include <iostream>

struct Node
{
    int priority;
    int data; 
    Node* next;

    Node(int data, int priority)
    {
        this->data = data;
        this->priority = priority;
        next = NULL;
    }
};

class PriorityQueue
{
private:
    Node* front;

public:
    PriorityQueue()
    {
        front = NULL;
    }

    void insert(int data, int priority)
    {
        Node* new_node = new Node(data, priority);

        if(front == NULL || new_node->priority > front->priority)
        {
            new_node->next = front;
            front = new_node;
        }

        else
        {
            Node* ptr = front;
            while(ptr->next != NULL && ptr->next->priority >= priority)
                ptr = ptr->next;

            new_node->next = ptr->next;
            ptr->next = new_node;

        }
    }

    void pop()
    {
        
        if(front == NULL)
            std::cout<< "Queue is empty"<< std::endl;

        else
        {
            Node* ptr = front;
            std::cout << "Deleted item:" << front->data << std::endl;
            front = front->next;
            delete ptr;
        }

    }
    Node* find(int data){
        if(front == NULL){
            std::cout << "Queue empty";
            return NULL;
        }
        Node* temp = front;
        do{
            if(temp->data == data){
               return temp;
            }
            temp = temp->next;
        }while(temp != NULL);

        std::cout << "Couldn't find node with correct data ";
        return NULL;
    }

    Node* find(int data){
         if(front == NULL)
            std::cout << "Queue is empty"<< std::endl;
        else
        {
            Node* ptr = front;
            if(ptr->data == data){
                std::cout << "Item found with priority: " << ptr->priority;
                return ptr;
            }
            while(ptr->next != NULL){
                ptr = ptr->next;
                if(ptr){
                    if(ptr->data == data){
                        std::cout << "Item found with priority:" << ptr->priority;
                        return ptr;
                    }
                }
            }
            std::cout << "Item not found\n";
            return 0;
        }
        return 0;
    }

    void displayList()
    {
        if(front == NULL)
            std::cout << "Queue is empty"<< std::endl;
        else
        {
            Node* ptr = front;
            std::cout << "\n[Priority]" << "\t" << "[Item]" << std::endl;
            while(ptr != NULL)
            {
                std::cout << ptr->priority << "   \t\t" << ptr->data << std::endl;
                ptr = ptr->next;
            }
        }
    }

};


int main()
{
    PriorityQueue pq;
    pq.insert(1,2);
    pq.insert(1,3);
    pq.insert(3,2);
    pq.insert(3,1);
    pq.displayList();
    pq.pop();
    Node* n = pq.find(1);
    pq.displayList();
    Node* foundItem = pq.find(3);
    std::cout << "Found item " << foundItem->data << " with priority " << foundItem->priority;


}