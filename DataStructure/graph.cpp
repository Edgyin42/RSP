#include "graph.hpp"


int main(){
    graph *a = new graph(true, 9); 
    a->addEdges(0, 1, false); 
    a->addEdges(0, 2, false); 
    a->addEdges(0, 6, false); 
    a->addEdges(6, 7, false); 
    a->addEdges(0, 7, false); 
    a->addEdges(2, 7, false); 
    a->addEdges(2, 4, false); 
    a->addEdges(2, 1, false); 
    a->addEdges(5, 1, false); 
    a->addEdges(5, 3, false); 
    a->addEdges(3, 1, false); 
    a->addEdges(4, 8, false); 
    a->addEdges(3, 8, false); 
    a->printGraph(); 
    

}