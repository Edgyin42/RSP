
#include <iostream>
using namespace std;

class singleton{
    private: 
        char a; 
        int num;
        static singleton *instancePtr;
        singleton(){} 
    public:
        static singleton* getInstance(){
            if (instancePtr == nullptr){
                instancePtr = new singleton; 
                return instancePtr; 
            } else{
                return instancePtr; 
            }
        }

        void setSingleton(int a, char b){
            num = a;
            this->a = b;  
        }
        
        void print(){
            cout << "Character: " << this->a << "; " << "number: " << this->num << endl; 
        }
}; 

singleton* singleton::instancePtr = nullptr;

int main(){
    singleton *obj1 = singleton::getInstance(); 
    obj1->setSingleton(1, 'A'); 
    obj1->print(); 
    
    cout << "The address of object 1 is: " << obj1 << endl; 

    singleton *obj2 = singleton::getInstance(); 
    obj2->setSingleton(1, 'B'); 
    obj2->print(); 
    cout << "The address of object 2 is: " << obj2 << endl; 
}