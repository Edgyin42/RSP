#include <iostream> 
#include <string> 
using namespace std; 


#define MATCH 0
#define INSERT 1
#define DELETE 2

int indel(){
    return 1; 
}


int match(char a, char b){
    if (a == b){
        return 0; 
    }
    else{
        return 1; 
    }
}

int string_compare(char *s, char *t, int i, int j){
    int opt[3]; 
    int lowest_cost; 

    if (i == 0) return j*indel(); 
    if (j == 0) return i*indel(); 

    opt[MATCH] = string_compare(s, t, i-1, j-1) + match(s[i], t[j]); 
    opt[INSERT] = string_compare(s, t, i, j-1) + indel(); 
    opt[DELETE] = string_compare(s, t, i-1, j) + indel(); 

    lowest_cost = opt[MATCH]; 
    for (int i = INSERT; i <= DELETE; i++){
        if (lowest_cost > opt[i]) lowest_cost = opt[i]; 
    }
    return lowest_cost; 
}   

int main(){
    char s[] = "helloworld"; 
    char t[] = "hed";
    int i = string_compare(&s[0], &t[0], 10, 2); 
    cout << i;  
}