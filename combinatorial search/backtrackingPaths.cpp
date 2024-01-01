#include "../DataStructure/graph.hpp" 
#include <iostream>
using namespace std; 

bool is_a_solution(int *state, int k, int d){
    return state[k] == d; 
}

void printSolution(int *state, int n){
    for (int i = 0; i < n; i++){
        if (state[i] != -1){
            cout << state[i] << " ";
        }
    }
    cout << endl; 
}

void generateCandidate(graph *g, int n, int k, int* state, int *nC, int *C){
    bool *inSol = new bool[n]; 

    for (int i = 0; i < n; i++){
        inSol[i] = false;
    }

    for (int i = 0; i < k; i++){
        inSol[state[i]] = true;
    }

    if (k == 0){
        *nC = 1; 
        C[0] = 0; 
    }
    else{
        *nC = 0; 
        int last = state[k-1];
        edgeNode *p = g->edges[last]; 
        while (p){
            if (!inSol[p->y]){
                C[*nC] = p->y; 
                *nC = *nC + 1; 
            }
            p = p->next;
        }
    }
}

void backtrack(graph *g, int n, int k, int d, int* state){
    if (is_a_solution(state, k, d)){
        printSolution(state, n);
    }

    else{
        k ++; 

        int *nC = new int; 
        int *C = new int[n-k]; 

        generateCandidate(g,n,k,state,nC,C); 

        for (int i = 0; i < *nC; i++){
            state[k] = C[i];
            backtrack(g, n, k, d, state); 
        }
    }
}

int main(){
    graph *g = new graph(false, 6); 

    g->addEdges(0, 1, false);
    g->addEdges(0, 4, false);
    g->addEdges(0, 2, false);
    g->addEdges(0, 3, false);
    g->addEdges(1, 5, false);
    g->addEdges(2, 5, false);
    g->addEdges(3, 5, false);
    g->addEdges(4, 5, false);

    int *state = new int[6];

    for (int i = 0; i < 6; i++){
        state[i] = -1; 
    }

    backtrack(g, 6, -1, 3, state); 
}