#include <iostream> 
using namespace std; 

#define MAXLEN 10 
#define MATCH 0
#define INSERT 1
#define DELETE 2

struct cell{
    int parent; 
    int cost; 
};

cell c[MAXLEN + 1][MAXLEN +1];

void row_init_cell(int i){
    c[i][0].cost = i; 
    if (i != 0){
        c[i][0].parent = INSERT; 
    }
    else{
        c[i][0].parent = -1; 
    }
}; 

void column_init_cell(int i){
    c[0][i].cost = i; 
    if (i != 0){
        c[0][i].parent = DELETE; 
    }
    else{
        c[0][i].parent = -1; 
    }
}; 

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

int string_compare(char *s, char *t){

    int opt[3]; 
    for (int i = 0; i <= MAXLEN; i++){
        row_init_cell(i);
        column_init_cell(i); 
    }

    for (int i = 1; i <= MAXLEN; i++){
        for (int j = 1; j <= MAXLEN; j++){
            opt[MATCH] = c[i-1][j-1].cost + match(s[i], t[j]); 
            opt[INSERT] = c[i][j-1].cost + indel(); 
            opt[DELETE] = c[i-1][j].cost + indel(); 
            c[i][j].cost = opt[MATCH]; 
            c[i][j].parent = MATCH; 
            for (int i = INSERT; i <= DELETE; i++){
                if (c[i][j].cost > opt[i]){
                    c[i][j].cost = opt[i]; 
                    c[i][j].parent = i; 
                }; 
            }
        }
    }

    return (c[strlen(s)-1][strlen(t)-1].cost); 
}


int main(){
    char s[] = "helloworld"; 
    char t[] = "hed";
    int i = string_compare(&s[0], &t[0]); 
    cout << i;  
}
