#include <iostream>
#include <vector>

#define M 6 // number of graph vertices

void printMST(int parents[],int graph[M][M]){
    for(int i = 1; i<M;i++){
        std::cout << parents[i] << " - " << i << "\t" <<graph[i][parents[i]] << "\n";
    }
}
// used to get the key with smallest value from a set of vertices
int minKey(int keys[], bool inMST[])
{
    int min = INT_MAX;
    int min_index;

    for(int i = 0; i < M; i++){
        if(inMST[i] == false && keys[i] < min){
            min = keys[i];
            min_index = i;
        }
    }
    return min_index;
}

void primAlgorithmMST(int graph[M][M]){
    int keys[M]; // key values 
    int parents[M]; // array storing constructed Minimal Spanning Tree
    bool inMST[M]; // used to check whether a vertex has already been added to the tree

    // Initializing all the keys as max value and inMST array as false
    for(int i = 0; i<M; i++){
        keys[i] = INT_MAX;
        inMST[i] = false; 
    }

    keys[0] = 0; // choosing vertex to be picked first(in this case the first one)
    parents[0] = -1 ;// -1 means the vertex has no parents(it is the root)

    for(int c = 0; c < M; c++){
        int pick = minKey(keys, inMST); // pick the key with lowest value that's not yet been added to the tree
        inMST[pick] = true; // the key has been visited, change bool value accordingly

        for(int b = 0; b<M; b++){
            if(graph[pick][b] && inMST[b] == false && graph[pick][b] < keys[b]){
                parents[b] = pick;
                keys[b] = graph[pick][b];
            }
        }
    }
    printMST(parents,graph);
}



int main()
{
    int graph[M][M] = { { 0, 2, 0, 6, 0, 0},
                        { 2, 0, 3, 8, 5, 1},
                        { 0, 3, 0, 0, 7, 2},
                        { 6, 8, 0, 0, 9, 3},
                        { 0, 5, 7, 9, 0, 4},
                        { 1, 4, 0, 3, 2, 0} };
    primAlgorithmMST(graph);
}