

struct Node
{
int data;
Node* left;  // left child
Node* right; // right child

Node(int x)
{
    data = x;
    left = nullptr;
    right = nullptr;
}

};

class BinaryTree
{
    Node* root;
    Node* createNode(int x);

public: 

    BinaryTree();  
    bool isEmpty();
    void insert(int item);
    void displayBinaryTree();
    void printBinaryTree(Node* ptr);

    void inOrder_sequence(Node* ptr);
    void inOrderTraversal();

    void postOrder_sequence(Node* ptr);
    void postOrderTraversal();

    void preOrder_sequence(Node* ptr);
    void preOrderTraversal();

};