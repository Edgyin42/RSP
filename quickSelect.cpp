#include <iostream>
using namespace std;

int partition(int *arr, int low, int high){
    int firstHigh = low; 
    int p = high;
    for (int i = low; i < high; i++){
        if (arr[i] < arr[p]){
            swap(arr[i], arr[firstHigh]); 
            firstHigh++; 
        }
    }
    swap(arr[p], arr[firstHigh]); 
    return firstHigh;
}

int quicksort(int *arr, int low, int high, int index){
    
    int p = partition(arr, low, high); 
    if (index < p) // if the index is less than the partition position
        return quicksort(arr, low, p-1, index); //if the index is greater than the partition position
    else if (index > p)
        return quicksort(arr, p+1, high, index); 
    else return arr[index]; //found the right number. 
}

int quickselect(int *arr, int length, int k){
    int index = length - k; 
    return quicksort(arr, 0, length -1, index); 
}



int main(){
    int arr[6] = {3, 2, 1, 5, 6, 4}; 
    int k = 3; 

    int size = sizeof(arr)/ sizeof(arr[0]);
    int num = quickselect(&arr[0], size, k);
    cout << num << endl; 
}