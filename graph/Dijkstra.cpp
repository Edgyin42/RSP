#include "../DataStructure/graph.hpp"


void printDijkstra(graph *g, int *parent, int *distance){
    for (int i = 0; i < g->nVertices; i++){
        cout << "Shortest path to " << i << " is " << distance[i] << " long." << endl;  
        cout << "This is the path through "; 
        int p = parent[i]; 
        while (p != -1){
            cout << p << " "; 
            p = parent[p]; 
        }
        cout << endl; 
    }
}

void dijkstra(graph *g, int start){
    int *parent = new int[g->nVertices]; 
    int *distance = new int[g->nVertices]; 
    bool *intree = new bool[g->nVertices]; 

    for (int i = 0; i < g->nVertices; i++){
        parent[i] = -1; 
        distance[i] = INT32_MAX; 
        intree[i] = false; 
    }

    distance[start] = 0; 
    int v = start; 

    while (!intree[v]){
        intree[v] = true; 
        edgeNode *p = g->edges[v]; 
        
        while (p){
            int w = p->y; 
            int weight = p->weight; 

            if (distance[w] > distance[v] + weight){
                distance[w] = distance[v] + weight; 
                parent[w] = v; 
            }
            p = p->next; 
        }

        v = 1;
        int dist =  numeric_limits<int>::max();

        // Select the next vertex to assess
        for (int i = 0; i < g->nVertices; i++) {
            if (distance[i] < dist && intree[i] == false) {
                dist = distance[i];
                v = i;
            }
        }
    }

    printDijkstra(g, parent, distance); 
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
    dijkstra(a, 0); 
}