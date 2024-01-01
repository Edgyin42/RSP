#include "linkedList.hpp"


int main(){
    linkedList *a = new linkedList; 
    a->insert(5); 
    a->insert(4); 
    a->insert(3); 
    a->insert(2); 
    a->insert(1); 
    a->display(); 


    Node *b = a->search(3); 
    cout << b->_value << endl; 


    a->remove(3); 
    a->display(); 

}