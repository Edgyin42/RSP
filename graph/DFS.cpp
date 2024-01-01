#include "../DataStructure/graph.hpp"
#include <queue>
using namespace std; 

class DFS{
    public:
    graph *a; 
    bool *processed; 
    bool *discovered; 
    int time; 
    int *entryTime; 
    int *exitTime; 
    int *parent;

    DFS(){
        a = new graph(false, 9); 
        processed = new bool[a->nVertices]; 
        discovered = new bool[a->nVertices]; 
        entryTime = new int[a->nVertices]; 
        exitTime = new int[a->nVertices]; 
        parent = new int[a->nVertices];
        time = 0;  

        for (int i = 0; i < a->nVertices; i++){
            processed[i] = false; 
            discovered[i] = false;
            entryTime[i] = 0;
            exitTime[i] = 0;
            parent[i] = 0;
        }
    }

    void processedVertexEarly(int x){
        cout << endl; 
        cout << "Processed vertex " << x << endl << endl; 
    }

    void processedEdge(int x, int y){
        cout << "Processed edge " << x << " " << y << endl; 
    }

    void processedVertexLate(int x){
    }

    void traverseDFS(int start){
        edgeNode *curr = a->edges[start]; 
        int y; 

        discovered[start] = true; 
        time ++; 
        entryTime[start] = time; 

        processedVertexEarly(start); 

        while (curr){
            y = curr->y; 

            if (!discovered[y]){
                parent[y] = start;
                discovered[y] = true; 
                processedEdge(start, y); 
                traverseDFS(y); 
            }
            else if (!processed[y] || a->directed){
                processedEdge(start, y); 
            }

            curr = curr->next;
        }
        processedVertexLate(start); 

        time++; 
        exitTime[start] = time; 
        
        processed[start] = true;
    }

    void findPaths(int start, int end){
        if (start == end){
            cout << start << " "; 
        }
        else{
            findPaths(start, parent[end]); 
            cout << end << " "; 
        }
    }

    void processedEdgeCycles(int x, int y){
        if (parent[x] != y) {//back edges
            cout << "Cycle from " << y << "to " << x << endl; 
            findPaths(y, x); 
        }
    }

    void traverseDFScycles(int start){
        edgeNode *curr = a->edges[start]; 
        int y; 

        discovered[start] = true; 
        time ++; 
        entryTime[start] = time; 

        processedVertexEarly(start); 

        while (curr){
            y = curr->y; 

            if (!discovered[y]){
                parent[y] = start;
                discovered[y] = true; 
                processedEdgeCycles(start, y); 
                traverseDFS(y); 
            }
            else if (!processed[y] || a->directed){
                processedEdge(start, y); 
            }

            curr = curr->next;
        }
        processedVertexLate(start); 

        time++; 
        exitTime[start] = time; 
        
        processed[start] = true;
    }
}; 


int main(){
    DFS *D = new DFS;  
    D->a->addEdges(0, 1, false); 
    D->a->addEdges(0, 2, false); 
    D->a->addEdges(0, 6, false); 
    D->a->addEdges(6, 7, false); 
    D->a->addEdges(0, 7, false); 
    D->a->addEdges(2, 7, false); 
    D->a->addEdges(2, 4, false); 
    D->a->addEdges(2, 1, false); 
    D->a->addEdges(5, 1, false); 
    D->a->addEdges(5, 3, false); 
    D->a->addEdges(3, 1, false); 
    D->a->addEdges(4, 8, false); 
    D->a->addEdges(3, 8, false); 
    D->traverseDFS(0); 

    


}