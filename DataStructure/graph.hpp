#include <iostream> 
using namespace std; 

struct edgeNode{
    public:

    int x; 
    int y; 
    int weight; 
    edgeNode *next; 

    edgeNode(){
        this->x = 0; 
        this->y = 0; 
        this->weight = 0; 
        this->next = nullptr; 
    }

    edgeNode(int weight, int x, int y){
        this->x = x; 
        this->y = y; 
        this->weight = weight; 
        this->next = nullptr; 
    }
}; 



class graph{
    public: 
    edgeNode **edges; 
    int nVertices; 
    int nEdges; 
    bool directed; 
    int *degrees; 


    public: 
    graph(bool directed, int nVertices){
        this->nVertices = nVertices; 
        this->edges = new edgeNode*[nVertices]; 
        this->directed = directed; 
        this->nEdges = 0; 
        this->degrees = new int[nVertices]; 
        for (int i = 0; i < nVertices; ++i){
            this->edges[i] = nullptr; 
            this->degrees[i] = 0; 
        }
    } 

    void addEdges(int x, int y, bool directed, int weight = 0){
        edgeNode *newEdge = new edgeNode(weight, x, y); 
        newEdge->next = this->edges[x]; 
        this->edges[x] = newEdge; 
        if (!directed){
            addEdges(y, x, true, weight); 
        } 
        else{
            this->nEdges++; 
        }
        this->degrees[x]++; 
    }

    void printGraph(){
        cout << "Number of vertices: " << this->nVertices << endl; 
        cout << "Number of edges: " << this->nEdges << endl; 
        for (int i = 0; i < this->nVertices; i++){
            edgeNode *p = this->edges[i]; 
            cout << "Vertice " << i << " is connnect to: "; 
            while (p){
                cout << p->y << " "; 
                p = p->next; 
            }
            cout << endl; 
        }
    }
}; 