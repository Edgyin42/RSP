#include "queue.hpp"


int main(){
    queue *a = new queue; 
    a->enqueue(1); 
    a->enqueue(2); 
    a->enqueue(3); 
    a->enqueue(4); 
    a->enqueue(5); 

    a->disp(); 

    a->dequeue(); 
    a->disp(); 


}