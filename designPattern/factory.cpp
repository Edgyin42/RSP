
#include <iostream>
using namespace std;

enum burgerType{
    cheeseBurgerType, 
    deluxeBurgerType,
    veganBurgerType,
};

class burger{
    public:
    burger(){}
    virtual void printIngredients() = 0; 
    virtual ~burger(){}
}; 

class cheeseBurger: public burger{
    public:
    cheeseBurger(){}
    void printIngredients(){
        cout << "This burger contains cheese, bun and beef-batty." << endl; 
    }
}; 

class deluxeBurger: public burger{
    public:
    deluxeBurger(){}
    void printIngredients(){
        cout << "This burger contains tomato, bun, lettuce, cheese and beef-batty." << endl; 
    }
}; 

class veganBurger: public burger{
    public:
    veganBurger(){}
    void printIngredients(){
        cout << "This burger contains special sauce, bun and veggie-batty."<< endl; 
    }
}; 


class burgerFactory{
    public:
        burger* sell(burgerType type){
            if (type == cheeseBurgerType){
                return new cheeseBurger; 
            }
            else if (type == deluxeBurgerType){
                return new deluxeBurger; 
            }
            else if (type == veganBurgerType){
                return new veganBurger; 
            }
            else{
                return nullptr;
            }
        }
}; 


class client{
    private: 
    burger* newBurger; 
    public: 
    client(){ newBurger = nullptr; }

    burger *sellBurger(burgerType type){
        burgerFactory *a = new burgerFactory; 
        newBurger = a->sell(type); 
        delete a; 
        return newBurger; 
    }

    ~client(){
        if (newBurger){
            delete newBurger; 
        }
    }

    burger *getBurger(){
        return newBurger; 
    }
}; 

int main(){
    client *c = new client; 
    c->sellBurger(cheeseBurgerType); 
    c->getBurger()->printIngredients(); 

    c->sellBurger(deluxeBurgerType); 
    c->getBurger()->printIngredients(); 

    c->sellBurger(veganBurgerType   ); 
    c->getBurger()->printIngredients(); 

    delete c; 
}