#include <iostream>
using namespace std;


struct setUnion{
    int *parent; //parent element
    int *size; //number of elements in subtree i
    int n; //number of elements in set. 


    setUnion(int n){
        n = n; 
        parent = new int[n];
        size = new int[n]; 
        for (int i = 0; i < n; i++){
            parent[i] = i; 
            size[i] = 1; 
        }
    }
};


int find(setUnion *a, int x){
    if (a->parent[x] == x){
        return x; 
    }
    else{
        return find(a, a->parent[x]);
    }
}

void unionSets(setUnion *a, int s1, int s2){
    int r1 = find(a, s1);
    int r2 = find(a, s2);

    if (r1 == r2){
        return; 
    }

    else if (a->size[r1] >= a->size[r2]){
        a->size[r1] = a->size[r1] + a->size[r2]; 
        a->parent[r2] = r1; 
    }

    else{
        a->size[r2] = a->size[r2] + a->size[r1]; 
        a->parent[r1] = r2;
    }
}

bool sameComponent(setUnion *a, int s1, int s2){
    return (find(a, s1) == find(a, s2)); 
}