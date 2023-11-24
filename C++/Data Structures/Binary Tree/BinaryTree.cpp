#include "BinaryTree.h"
#include <iostream>


BinaryTree::BinaryTree()
{
    root = nullptr;
}


bool BinaryTree::isEmpty()
{
    return (root == nullptr);
}   



Node* BinaryTree::createNode(int item)
{
    Node* new_node = new Node(item);
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;
}



void BinaryTree::insert(int item)
{
    Node* new_node = createNode(item);

    if(isEmpty()){
        root = new_node;
    }

    else{
        Node* ptr = root;
        Node* parent;

        while(ptr != NULL)   // traversing through tree until we find an empty space
        {
            parent = ptr;

            if(item > ptr->data)  // go left if the inserted value is lower than the previous value
            {
                ptr = ptr->right;
            }

            else                    // go right otherwise
            {
                ptr = ptr->left;
            }
        }

        if(item < parent->data)     // finally when we find an empty space we choose if the node will be the left or right child based on previous rules
            parent->left = new_node;
        
        else 
            parent->right = new_node;

    }
}

void BinaryTree::printBinaryTree(Node* ptr)
{
    if(ptr!=NULL)
    {
        std::cout << " " << ptr->data << "   " ;
        printBinaryTree(ptr->left);
        printBinaryTree(ptr->right);
    }
}

void BinaryTree::displayBinaryTree()
{
    printBinaryTree(this->root);
}

void BinaryTree::inOrder_sequence(Node* ptr)
{
    if(ptr != NULL)
    {
        inOrder_sequence(ptr->left);
        std::cout << " " << ptr->data;
        inOrder_sequence(ptr->right);
    }
}

void BinaryTree::inOrderTraversal()  // starts the recursion on root node
{
    inOrder_sequence(root);
}

void BinaryTree::postOrder_sequence(Node* ptr)
{
    if(ptr != NULL)
    {
        inOrder_sequence(ptr->left);
        inOrder_sequence(ptr->right);
        std::cout << " " << ptr->data;
    }
}

void BinaryTree::postOrderTraversal()  // starts the recursion on root node
{
    postOrder_sequence(root);
}

void BinaryTree::preOrder_sequence(Node* ptr)
{
    if(ptr != NULL)
    {
        std::cout << " " << ptr->data;
        preOrder_sequence(ptr->left);
        preOrder_sequence(ptr->right);
    }
}

void BinaryTree::preOrderTraversal()  // starts the recursion on root node
{
    preOrder_sequence(root);
}