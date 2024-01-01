#include <iostream> 

struct adjMatrix{
    public:
    int **weight; 
    int nVertices; 

    adjMatrix(int n){
        this->nVertices = n; 
        weight = new int*[n]; 
        for (int i = 0; i < n; i++){
            weight[i] = new int[n]; 
            for (int j = 0; j < n; j++){
                weight[i][j] = INT16_MAX; 
            }
        }
    }

    void addEdges(int i, int j, int edgeWeight){
        weight[i][j] = edgeWeight; 
        weight[j][i] = edgeWeight; 
    }
};