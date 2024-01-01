#include "../DataStructure/weightedAdjacencyMatrix.hpp"
using namespace std; 


void floydWashallPrint(adjMatrix* a) {
    for (int i = 0; i < a->nVertices; i++) {
        for (int j = 0; j < a->nVertices; j++) {
            cout << "Path " << i << " to " << j << " is " << a->weight[i][j] << " units." << endl; 
        }
    }
}


void floydMarshall(adjMatrix *a){
    for (int i = 0; i < a->nVertices; i++){
        for (int j = 0; j < a->nVertices; j++){
            for (int k = 0; k < a->nVertices; k++){
                int through_k = a->weight[i][k] + a->weight[k][j]; 
                if (through_k < a->weight[i][j]){
                    a->weight[i][j] = through_k; 
                }
            }
        }
    }
    floydWashallPrint(a); 
}



int main(){
    adjMatrix *a = new adjMatrix(7); 
    a->addEdges(0, 1, 5); 
    a->addEdges(1, 2, 7); 
    a->addEdges(2, 3, 5); 
    a->addEdges(3, 4, 2); 
    a->addEdges(4, 5, 7); 
    a->addEdges(0, 5, 12); 
    a->addEdges(0, 6, 7); 
    a->addEdges(1, 6, 9); 
    a->addEdges(2, 6, 4); 
    a->addEdges(4, 6, 3); 
    a->addEdges(2, 4, 2); 
    floydMarshall(a); 

}