#include "BinaryTree.h"
#include <iostream>



int main()
{
    BinaryTree tree;

    tree.insert(15);
    tree.insert(16);
    tree.insert(17);
    tree.insert(12);
    tree.insert(13);
    tree.insert(14);
    tree.insert(20);
    std::cout << "displayBinaryTree:";
    tree.displayBinaryTree();
    std::cout << "\n";
    std::cout << "postOrderTraversal:";
    tree.postOrderTraversal();
    std::cout << "\n";
    std::cout << "preOrderTraversal:";
    tree.preOrderTraversal();
    std::cout << "\n";
    std::cout << "inOrderTraversal:";
    tree.inOrderTraversal();
}


