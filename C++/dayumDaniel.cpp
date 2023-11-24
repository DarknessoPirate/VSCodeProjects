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

void dayumDaniel(Node* daniel, Node** coolerDaniel)
{
    daniel = new Node(1);
    *coolerDaniel = new Node(1);
}
int main()
{
    Node* daniel = NULL;
    Node* coolerDaniel = NULL;
    
    std::cout<< "daniel before drugs:\n";
    std::cout << daniel << " " << coolerDaniel << std::endl;
    std::cout << &daniel << " " << &coolerDaniel << std::endl;

    dayumDaniel(daniel, &coolerDaniel);

    std::cout << "daniel after drugs:\n";
    std::cout << daniel << " " << coolerDaniel << std::endl;
    std::cout << &daniel << " " << &coolerDaniel << std::endl;



}