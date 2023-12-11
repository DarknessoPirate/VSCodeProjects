#include <iostream>

#define V 4
#define INF INT_MAX

void printSolution(int distances[][V]){
    for(int i = 0; i < V; i++){
        for(int j = 0; j < V; j++){
            if(distances[i][j] == INF)
                std::cout << "INF ";
            else
                std::cout << distances[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void floydWarshall(int distances[][V]){
    int i,j,k;
    for(k = 0; k < V; k++){ // k - intermediate node we are checking
        for(j = 0; j < V; j++){ // j - the node from where we want to start searching
            for(i = 0; i < V; i++){ // i - the node we want to get to
                if(distances[j][i] > (distances[j][k] + distances[k][i]) 
                && distances[j][k] != INF && distances[k][i] != INF){
                    distances[j][i] = distances[j][k] + distances[k][i];
                }
            }
        }
    }
}


int main(){

int graph[V][V] = {
                    {0, 5, INF, 10},
                    {INF, 0, 3, INF},
                    {INF, INF, 0, 1},
                    {INF, INF, INF, 0}
                    };
floydWarshall(graph);
printSolution(graph);

}