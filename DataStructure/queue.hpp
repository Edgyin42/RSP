#include <iostream> 
using namespace std;

struct Node{
    int data;
    Node *next; 
    Node():data(0), next(nullptr){}
    Node(int value):data(value), next(nullptr){}
};


class queue{
    Node *first; 
    Node *last; 
    int size; 
    public:
    queue(): first(nullptr), last(nullptr){}


    void enqueue(int x){
        if (last == nullptr){
            last = new Node(x); 
            first = last; 
        }
        else{
            Node *a = new Node(x); 
            last->next = a; 
            last = a; 
        }
        size++; 
    }


    void dequeue(){
        if (first == nullptr){
            return; 
        }
        else{
            Node *tmp = first->next; 
            delete first; 
            first = tmp; 
        }
        size--;
    }

    void disp(){
        Node *curr = first; 
        while (curr != nullptr){
            cout << curr->data   << " "; 
            curr = curr->next;
        }
        cout << endl; 
    }

    bool isEmpty(){
        return size == 0; 
    }

    int peek(){
        return last->data; 
    }

};