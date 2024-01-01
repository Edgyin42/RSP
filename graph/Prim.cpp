#include "../DataStructure/graph.hpp"
#include <queue>
using namespace std; 

class Prim{
    public:
    graph *a; 
    bool *intree; 
    int *distance; 
    int *parent; 

    Prim(){
        a = new graph(false, 7); 
        intree = new bool[a->nVertices];
        distance = new int[a->nVertices];
        parent = new int[a->nVertices];
        for (int i = 0; i < a->nVertices; i++){
            intree[i] = false; 
            distance[i] = INT_MAX;  
            parent[i] = -1; 
        }
    }

    void prim(int start){
        edgeNode *p; 
        int v; //current vertex
        int w; //candidate next vertex
        int weight; // edge weight
        int dist; // best current distance from start

        distance[start] = 0; 
        v = start; 

        while (!intree[v]){
            intree[v] = true; 
            p = a->edges[v]; 

            while(p){
                w = p->y; 
                weight = p->weight; 
                if (distance[w] > weight && !intree[w]){
                    distance[w] = weight; 
                    parent[w] = v; 
                }
                p = p->next; 
            }

            v = 1;
            dist =  numeric_limits<int>::max();

            // Select the next vertex to assess
            for (int i = 0; i < a->nVertices; i++) {
                if (distance[i] < dist && intree[i] == false) {
                    dist = distance[i];
                    v = i;
                }
            }
        }
    }


}; 