#include <iostream> 
using namespace std; 


int fib(int n, int *fib_a){
    if (n == 1) return 0; 
    if (n == 2) return 1; 
    else{
        fib_a[n-1] = fib(n-1, fib_a); 
        fib_a[n-2] = fib(n-2, fib_a); 
        fib_a[n] = fib_a[n-1] + fib_a[n-2];
        return fib_a[n];
    }
}



int main(){
    int n = 6; 
    int fib_a[n+1];
    int a = fib(n, fib_a); 
    cout << a; 
}