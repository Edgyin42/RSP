#include "unionFind.hpp"

int main(){
    setUnion *a = new setUnion(9); 

    unionSets(a, 1, 2); 
    unionSets(a, 3, 5); 
    unionSets(a, 5, 8); 
    unionSets(a, 4, 9); 
    unionSets(a, 1, 5); 
    unionSets(a, 4, 1); 
    
    for (int i = 1; i <= 9; i++){
        cout << i << " " << a->parent[i] << endl; 
    }
    
}