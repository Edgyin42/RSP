#include <iostream>
using namespace std;

void printSolution(int *state, int n){
    for (int i = 0; i < n; i++){
        cout << state[i] << " ";
    }
    cout << endl; 
}

bool isSolution(int k, int n){
    return k==n-1; 
}


void constructCandidates(int *state, int k, int n, int *C, int *nC){
    bool *inPerm = new bool[n]; 
    for (int i = 0; i < n; i++){
        inPerm[i] = false; 
    }
    
    for (int j = 0; j < k; j++){
        inPerm[state[j]] = true; 
    }

    *nC = 0; 

    for (int i = 0; i < n; i++){
        if (!inPerm[i]){
            C[*nC] = i; 
            *nC = *nC + 1; 
        }
    }
}


void backtrack(int* state, int k, int n){
    if (isSolution(k, n))
        printSolution(state, n); 
    else{
        k++; 

        int *nC = new int; 
        int *C = new int[n-k];

        constructCandidates(state, k, n, C, nC); 

        for (int i = 0; i < *nC; i++){
            state[k] = C[i];
            backtrack(state, k, n);
        }
    }
}

int main(){
    int *state = new int[3]; 

    for (int i = 0; i < 3; i++){
        state[i] = -1; 
    }

    backtrack(state, -1, 3);
}