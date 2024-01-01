#include <iostream> 
using namespace std; 
struct Node{
    int _value; 
    struct Node *next; 
    Node(): _value(0), next(nullptr){}
    Node(int value): _value(value), next(nullptr){}
};

class linkedList{
    private:

    Node *head; 
    int nNodes; 
    public: 
    linkedList(): head(nullptr), nNodes(0){}; 
    
    
    // Iterative search O(n)
    Node *search (int data){
        return search(head, data); 
    }

    Node* search(Node* a, int data){
        if (a == nullptr){
            return nullptr; 
        }
        if (a->_value == data){
            return a; 
        }
        else{
            return search(a->next, data); 
        }
    }
    //Insert at the beginning O(1)
    void insert(int data){
        // if the list is empty
        if (head == nullptr){
            head = new Node(data); 
        }
        else{
            Node *newNode = new Node(data); 
            newNode->next = head; 
            head = newNode; 
        }
        nNodes++; 
    }

    //Delete node from the list. O(n)
    Node *predecessor(Node * a, int data){
        if (a == nullptr){
            return nullptr; 
        }
        if (a->next->_value == data){
            return a; 
        }
        else{
            return predecessor(a->next, data); 
        }
    }

    void remove(int data){
        if (head == nullptr){
            return; 
        }
        if (head->_value == data){
            delete head; 
            head = nullptr; 
        }
        else{
            Node *pred = predecessor(head, data); 
            if (pred == nullptr){
                return;
            }

            Node *temp = pred->next->next; 
            delete pred->next; 
            pred->next = temp;
        }
    }


    //Display the entire list. 
    void display(){
        Node *curr = head; 
        while (curr != nullptr){
            cout << curr->_value << " "; 
            curr = curr->next; 
        }
        cout << endl; 
    }
    
}; 