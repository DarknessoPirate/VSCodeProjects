#include <iostream>

#define M 9

void printPath(int distance[])
{
    std::cout << "Vertex distance from root: \n";
    for(int i = 1; i<M; i++){
        std::cout << i << "\t" << distance[i] << std::endl;
    }
}
// returns index of a vertex with minimum distance value from the set
int minDist(int distance[], bool inSPT[]){// spt-shortest path tree
    int min = INT_MAX;  // init as infinity for the sake of comparison below
    int min_index;

    for(int i = 0; i<M; i++){
        if(inSPT[i] == false && distance[i] <= min){
            min = distance[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int graph[M][M], int rootIndex){
    int distances[M]; // used to hold distance from root values for each index
    bool inSPT[M]; // used to determine whether we have already put the vertex in the SPT

    for(int i = 0; i<M;i++){
        distances[i] = INT_MAX; // initializing all with infinity
        inSPT[i] = false; // initializing all as false 
    }

    distances[rootIndex] = 0; // choosing the root as the first element(it will be picked first thanks to the value of 0)

    // Finding shortest path for all vertices
    for(int c = 0; c<M; c++){
        // choosing the element
        int pick = minDist(distances,inSPT);
        inSPT[pick] = true; // element has been picked
        // looking for the shortest path to all vertices from vertex u
        for(int v = 0; v<M;v++){
            if(!inSPT[v] && graph[pick][v] && distances[pick] != INT_MAX
            && distances[pick] + graph[pick][v] < distances[v])
            {
                distances[v] = distances[pick] + graph[pick][v];
            }
        }
    }
    printPath(distances);
}



int main()
{
    int graph[M][M] = { { 0, 4, 0, 0, 3, 0, 0, 8, 0 },
                        { 4, 0, 8, 0, 0, 2, 0, 11, 0 },
                        { 0, 8, 0, 7, 0, 4, 0, 0, 2 },
                        { 0, 0, 7, 0, 9, 14, 0, 0, 0 },
                        { 0, 0, 0, 9, 0, 11, 0, 0, 1 },
                        { 0, 0, 4, 5, 7, 0, 2, 0, 0 },
                        { 0, 0, 0, 0, 0, 2, 0, 1, 6 },
                        { 8, 4, 0, 0, 0, 0, 1, 0, 7 },
                        { 2, 0, 2, 0, 0, 0, 6, 7, 0 } };


    dijkstra(graph,0);
}