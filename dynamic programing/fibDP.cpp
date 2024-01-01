#include <iostream>
using namespace std; 

int fib(int n){
    int a1 = 0; 
    int a2 = 1; 

    for (int i = 2; i < n-1; i++){
        int next = a1 + a2; 
        a1 = a2; 
        a2 = next; 
    }
    return a1 + a2;  
}

int main(){
    int a = fib(5); 
    cout << a; 
}