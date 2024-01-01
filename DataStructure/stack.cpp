#include "stack.hpp" 


int main(){
    stack *a = new stack; 
    a->push(5); 
    a->push(4); 
    a->push(3); 
    a->push(2); 
    a->push(1); 

    a->disp(); 

    a->pop(); 
    a->disp(); 

}