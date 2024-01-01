#include <iostream>
using namespace std; 
struct Node{
    int data;
    Node *next; 
    Node():data(0), next(nullptr){}
    Node(int value):data(value), next(nullptr){}
};



class stack{
    int size; 
    Node *top;  
    public: 
    stack(): size(0), top(nullptr){}


    //O(1)
    void push(int x){
        if (top == nullptr){
            top = new Node(x); 
        }
        else{
            Node *a = new Node(x); 
            a->next = top; 
            top = a; 
        }
        size++;
    }

    //O(1)
    void pop(){
        if (top == nullptr){
            return; 
        }
        else{
            Node *tmp = top->next; 
            delete top; 
            top = tmp; 
        }
        size--;
    }

    
    bool isEmpty(){
        return size == 0; 
    }

    int peek(){
        return top->data; 
    }

    void disp(){
        Node *curr = top; 
        while (curr != nullptr){
            cout << curr->data   << " "; 
            curr = curr->next;
        }
        cout << endl; 
    }
};