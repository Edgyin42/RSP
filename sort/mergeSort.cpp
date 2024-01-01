#include <iostream>
#include <queue> 
using namespace std; 
void merge(int array[], int low, int middle, int high){
    int s = low; // Index of s.

    // Initialize 2 queues buffer to store 2 subarrays; 
    queue<int> buffer1; 
    queue<int> buffer2; 
    for (int i = low; i <= middle; i++){
        buffer1.push(array[i]); 
    }
    for (int i = middle+1; i <= high; i++){
        buffer2.push(array[i]); 
    }

    // Merge 2 array
    while( !buffer1.empty() && !buffer2.empty()){
        if (buffer1.front() <= buffer2.front()){
            array[s] = buffer1.front(); 
            buffer1.pop(); 
        } else{
            array[s] = buffer2.front(); 
            buffer2.pop(); 
        }
        s++;   
    }
    // Merge the rest. 
    while (!buffer1.empty()){
        array[s] = buffer1.front(); 
        buffer1.pop(); 
        s++; 
    }

    while (!buffer2.empty()){
        array[s] = buffer2.front(); 
        buffer2.pop(); 
        s++; 
    }
}

void mergeSort(int array[], int low, int high){
    if(low < high){
        int middle = (low+high)/2; 
        mergeSort(array, low, middle); 
        mergeSort(array, middle+1, high); 
        merge(array, low, middle, high);
    }
}

int main(){
    int arr[] = {8, 9, 7, 6};
    mergeSort(arr, 0, 3); 
    for (int i = 0; i < 4; i++){
        cout << arr[i] << " "; 
    }

}