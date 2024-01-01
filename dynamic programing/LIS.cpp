#include <iostream> 
using namespace std; 




int main(){
    int arr[] = {2, 4, 3, 5, 1, 7, 6, 9, 8}; 
    int n = sizeof(arr) / sizeof(arr[0]);
    
    int *l = new int[n]; 

    for (int i = 0; i < n; i++){
        l[i] = 1; 
    }

    for (int i = 1; i < n; i++){
        int maxLJ = l[0]; 
        for (int j = 1; j < i; j++){
            if (l[j] > maxLJ){
                maxLJ = l[j]; 
            }
        }
        if (arr[i] > arr[i-1]){
            l[i] = maxLJ + 1; 
        }
        else{
            l[i] = maxLJ;
        }
    }

    //int lis = l[0]; 

    for (int i = 0; i < n; i++){
        cout << l[i] << " "; 
    }
    //cout << lis; 
    delete [] l;
}
