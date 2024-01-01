#include <iostream>
using namespace std; 

int bc(int **BC, int n, int k){
    BC = new int*[n+1]; 
    for (int i = 0; i <= n; i++){
        BC[i] = new int[n+1]; 
    }

    for (int i = 0; i <= n; i++){
        BC[i][0] = 1; 
        BC[i][i] = 1; 
        
    }
    for (int i = 2; i <= n; i++){
        for (int j = 1; j < i ; j++){
            BC[i][j] = BC[i-1][j-1] + BC[i-1][j];
        }
    }
    return BC[n][k]; 
}

int main(){
    int **BC; 
    int n = 5; 
    int k = 3; 
    int a = bc(BC, n, k-1);
    cout << a; 
}