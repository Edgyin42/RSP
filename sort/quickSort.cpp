#include <iostream>
#include <utility>
using namespace std;

int partition(int arr[], int low, int high){
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


void quickSort(int arr[], int low, int high){
    if (low < high){
        int p = partition(arr, low, high); 
        quickSort(arr, low, p-1);
        quickSort(arr, p+1, high); 
    }
}

int main(){
    int arr[] = {8, 9, 7, 6};
    quickSort(arr, 0, 3); 
    for (int i = 0; i < 4; i++){
        cout << arr[i] << " "; 
    }

}