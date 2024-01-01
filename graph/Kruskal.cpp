#include "../DataStructure/graph.hpp"
#include "../DataStructure/unionFind.hpp"
using namespace std; 


edgeNode **graphToEdgeArray(graph *g){ // Convert an adjacency list representation of a graph into an array of edges. 
    edgeNode **a = new edgeNode*[g->nEdges]; 
    int n = 0; 
    for (int i = 0; i < g->nVertices; i++){
        edgeNode *e = g->edges[i]; 

        while (e){
            a[n++] = e; 
            e = e->next; 
        }
    }
    return a; 
}

// quick sort
int partition(edgeNode **edgeArray, int low, int high){
    int firstHigh = low; 
    int p = high; 
    for (int i = low; i < high; i++){
        if (edgeArray[i]->weight < edgeArray[p]->weight){
            swap(edgeArray[i], edgeArray[firstHigh]); 
            firstHigh++; 
        }
    }
    swap(edgeArray[p], edgeArray[firstHigh]); 
    return firstHigh;
}


void quickSort(edgeNode **edgeArray, int low, int high){
    if (low < high){
        int p = partition(edgeArray, low, high); 
        quickSort(edgeArray, low, p-1); 
        quickSort(edgeArray, p+1, high); 
    } 
}


void kruskal(graph *g){
    setUnion *a = new setUnion(g->nVertices);

    edgeNode **array = graphToEdgeArray(g); 

    quickSort(array, 0, g->nVertices-1); 

    for (int i = 0; i < g->nEdges; i++){
        if (!sameComponent(a, array[i]->x, array[i]->y)){
            cout << "edge (" << array[i]->x << ", " << array[i]->y << ") " << "in MST" << endl; 
            unionSets(a, array[i]->x, array[i]->y); 
        }
    }
}

int main(){
    graph *a = new graph(false, 7); 
    a->addEdges(0, 1, false, 5);
    a->addEdges(1, 2, false, 7);
    a->addEdges(2, 3, false, 5);
    a->addEdges(3, 4, false, 2);
    a->addEdges(4, 5, false, 7);
    a->addEdges(5, 6, false, 4);
    a->addEdges(0, 6, false, 7);
    a->addEdges(0, 5, false, 12);
    a->addEdges(1, 6, false, 9);
    a->addEdges(2, 6, false, 4);
    a->addEdges(4, 6, false, 3);
    a->addEdges(4, 2, false, 2);
    kruskal(a); 
}