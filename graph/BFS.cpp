#include "../DataStructure/graph.hpp"
#include <queue>
using namespace std; 

class BFS{
    public: 
    graph *a; 
    bool *processed; 
    bool *discovered; 
    int *parent; 
    int *color; //1:white, 2:Black
    bool biparate; 

    public: 
    BFS(){
        a = new graph(false, 9); 
        processed = new bool[a->nVertices]; 
        discovered = new bool[a->nVertices]; 
        parent = new int[a->nVertices]; 

        color = new int[a->nVertices]; 
        biparate = true; 

        for (int i = 0; i < a->nVertices; i++){
            processed[i] = false; 
            discovered[i] = false;
            parent[i] = -1;  
            color[i] = 0; 

        }
    }


    void processedEdge(int x, int y){
        cout << "Processed edge " << x << " " << y << endl; 
    }

    void processedVertexEarly(int x){
        cout << endl; 
        cout << "Processed vertex " << x << endl << endl; 
    }

    void processedVertexLate(int x){
    }

    void traverseBFS(int start){
        std::queue<int> p; 
        edgeNode *h;
        p.push(start);
        int curr; //current vertex
        int y; 
        this->discovered[start] = true; 
        parent[start] = -1; 
        while(!p.empty()){
            curr = p.front(); 
            p.pop(); 
            processedVertexEarly(curr); 
            h = a->edges[curr]; 
            while(h){
                y = h->y; 
                if (!processed[y] || a->directed){
                    processedEdge(curr, y); 
                }
                if(!discovered[y]){
                    p.push(y); 
                    discovered[y] = true; 
                    parent[y] = curr; 
                }
                h = h->next; 
            }
            processedVertexLate(curr);
            processed[start] = true;
        }
    }

    //Find paths: 
    void findPaths(int start, int end){
        if (start == end){
            cout << start << " "; 
        }
        else{
            findPaths(start, parent[end]); 
            cout << end << " "; 
        }
    }

    //Count connected component: 
    void countConnectedComponents(){
        int c = 0; 

        for (int i = 0; i < a->nVertices; i++){
            if (discovered[i] == false){
                traverseBFS(i); 
                c++; 
                cout << "Component: " << i << endl; 
            }
        }
        cout << c; 
    }

    //two-coloring graphs: Check if a graph is biparate or not. 
    void processedEdge2Colors(int x, int y){
        if (color[x] == color[y]){
            biparate = false; 
            cout << "Not biparate due to " << x << "and " << y << endl; 
        }
        else{
            color[y] = complement(color[x]); 
        }
    }

    int complement(int x){
        if (color[x] == 1) return(2); 
        if (color[x] == 2) return(1); 

        return(0); 
    }

    void traverseBFS2color(int start){
        std::queue<int> p; 
        edgeNode *h;
        p.push(start);
        int curr; //current vertex
        int y; 
        this->discovered[start] = true; 
        parent[start] = -1; 
        while(!p.empty()){
            curr = p.front(); 
            p.pop(); 
            processedVertexEarly(curr); 
            h = a->edges[curr]; 
            while(h){
                y = h->y; 
                if (!processed[y] || a->directed){
                    processedEdge2Colors(curr, y); 
                }
                if(!discovered[y]){
                    p.push(y); 
                    discovered[y] = true; 
                    parent[y] = curr; 
                }
                h = h->next; 
            }
            processedVertexLate(curr);
            processed[start] = true;
        }
    }

    void twocolor(){
        for (int i = 0; i < a->nVertices; i++){
            if (discovered[i] == false){
                color[i] = 1;
                traverseBFS2color(i); 
            }
        }
        if (biparate)
            cout << "The graph is biparate." << endl; 
        else
            cout << "The graph is not biparate." << endl; 
    }
}; 

int main(){
    BFS *B = new BFS;  
    B->a->addEdges(0, 1, false); 
    B->a->addEdges(0, 2, false); 
    B->a->addEdges(0, 6, false); 
    B->a->addEdges(6, 7, false); 
    B->a->addEdges(0, 7, false); 
    B->a->addEdges(2, 7, false); 
    B->a->addEdges(2, 4, false); 
    B->a->addEdges(2, 1, false); 
    B->a->addEdges(5, 1, false); 
    B->a->addEdges(5, 3, false); 
    B->a->addEdges(3, 1, false); 
    B->a->addEdges(4, 8, false); 
    B->a->addEdges(3, 8, false); 
    B->traverseBFS(0); 
    cout << "Reverse path: "; 
    B->findPaths(0, 4); 
    
    cout << endl << "Connected component: ";
    B->countConnectedComponents();

    cout << endl;
    B->twocolor();
}