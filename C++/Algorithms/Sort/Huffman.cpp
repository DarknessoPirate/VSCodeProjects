#include <iostream>

#define MAX_HEIGHT 50

struct Node{
    unsigned int frequency;
    char letter;
    Node* left;
    Node* right;
};

struct Heap{
    unsigned int size;
    unsigned int capacity;
    Node** array;
};
// Used to create new nodes and initiate them
Node* newNode(char letter, unsigned int frequency){
    Node* new_node = new Node();
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->letter = letter;
    new_node->frequency = frequency;

    return new_node;
}

Heap* createMinHeap(unsigned int capacity){
    Heap* minHeap = new Heap();
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = new Node*[capacity]; // // // // //

    return minHeap;
}

void swapNodes(Node **a, Node **b){
    Node* temp = *a;
    *a = *b;
    *b = temp;
}

void Heapify(Heap* minHeap, int index){
    int smallest = index;
    int leftChild = 2*index+1;
    int rightChild = 2*index +2;

    if(leftChild < minHeap->size && minHeap->array[leftChild]->frequency < minHeap->array[smallest]->frequency)
        smallest = leftChild;

    if(rightChild < minHeap->size && minHeap->array[rightChild]->frequency < minHeap->array[smallest]->frequency)
        smallest = rightChild;    
    
    if(smallest != index){
        swapNodes(&minHeap->array[smallest], &minHeap->array[index]);
        Heapify(minHeap, smallest);
    }
}

Node* getMin(Heap* minHeap){
    Node* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    Heapify(minHeap, 0);

    return temp;
}

void insertIntoHeap(Heap* minHeap, Node* node){
    minHeap->size +=1;
    int index = minHeap->size-1;

    while(index && node->frequency < minHeap->array[(index-1)/2]->frequency){
        minHeap->array[index] = minHeap->array[(index-1)/2];
        index = (index-1)/2;
    }

    minHeap->array[index] = node;
}

void buildHeap(Heap* minHeap){
    int size = minHeap->size - 1;

    for(int i = (size-1)/2; i>=0; --i){
        Heapify(minHeap,i);
    }
}

int isLeaf(Node* root){
    return !(root->left) && !(root->right);
}

Heap* createAndBuildMinHeap(char letters[], int frequencies[], int size){
    Heap* minHeap = createMinHeap(size);

    for(int i = 0; i<size; ++i){
        minHeap->array[i] = newNode(letters[i],frequencies[i]);
    }

    minHeap->size = size;
    buildHeap(minHeap);

    return minHeap;

}

Node* buildHuffmanTree(char items[], int frequencies[],int size){
    Node* left, *right, *parent;
    Heap* minHeap = createAndBuildMinHeap(items,frequencies,size);

    while(minHeap->size != 1){
        left = getMin(minHeap);
        right = getMin(minHeap);

        parent = newNode('$', left->frequency + right->frequency);

        parent->left = left;
        parent->right = right;

        insertIntoHeap(minHeap, parent);
    }

    return getMin(minHeap);
}
void printArray(int* arr, int size){
    for(int i = 0; i<size;i++)
        std::cout << arr[i];

    std::cout << std::endl;
}

void printHuffmanCodes(Node* root, int arr[], int top){
    if(root->left){
        arr[top] = 0;
        printHuffmanCodes(root->left, arr, top+1);
    }

    if(root->right){
        arr[top] = 1;
        printHuffmanCodes(root->right,arr,top+1);
    }

    if(isLeaf(root)){
        std::cout << root->letter << " | ";
        printArray(arr,top);
    }
}


// Wrapper function
void GenerateHuffmanCodes(char letters[], int frequencies[], int size){
    Node* root = buildHuffmanTree(letters,frequencies,size);

    int arr[MAX_HEIGHT];
    int top = 0;

    printHuffmanCodes(root, arr, top);
}




int main(){
    char array[] = {'A', 'B', 'C', 'D','E'};
    int frequencies[] = {5, 1, 6, 3,11};

    int size = sizeof(array)/ sizeof(array[0]);
    std::cout << "Char | HCode" << std::endl;
    GenerateHuffmanCodes(array,frequencies,size);

}
