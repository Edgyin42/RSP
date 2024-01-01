#include <iostream>
using namespace std; 

void printSolution(int *s, int n){
    cout << "{ "; 
    
    for (int i = 0; i < n; i++){
        cout << s[i] << " "; 
    }

    cout << "}" << endl; 
}

bool is_a_solution(int k, int n){
    return (k == n); 
}


void backtrack(int *s, int k, int n){
    if (is_a_solution(k, n)){
        return printSolution(s, n);
    }
    else{
        k++; 
        int numSpace = 2; 
        int *nCandidates = new int[numSpace];
        nCandidates[0] = 0; // when the number is not in the subset
        nCandidates[1] = 1; // when the number is in the subset

        for (int i = 0; i < numSpace; i++){
            s[k-1] = nCandidates[i]; 
            backtrack(s, k, n); 
        }
    }
}

int main(){
    int n = 3; 

    int *s = new int[n]; 
    
    for (int i = 0; i < n; i++){
        s[i] = 0; 
    }

    backtrack(s, 0, n);
}