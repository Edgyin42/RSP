#include <iostream> 
using namespace std; 

#define DIMENSION 3
#define NCELL DIMENSION*DIMENSION

// struct point{
//     int x; 
//     int y; 
// };

class sudoku{
    public: 
    bool finish; 
    int board[DIMENSION][DIMENSION]; 

    sudoku(){
        finish  = false; 
        for (int i = 0; i < DIMENSION; i++){
            for (int j = 0; j < DIMENSION; j++){
                board[i][j] = 0; 
            }
        }
    }
};

bool isSolved(sudoku *a){
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            if (a->board[i][j] == 0){
                return false; 
            }
        }
    }
    return true; 
}

void printBoard(sudoku *a){
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            cout << a->board[i][j] << " ";
        }
        cout << endl; 
    }
}

int* findNextMove(sudoku *a){
    int *move = new int[2]; 
    for (int i = 0; i < DIMENSION; i++){
        for (int j = 0; j < DIMENSION; j++){
            if (a->board[i][j] == 0){
                move[0] = i; 
                move[1] = j; 
                return move; 
            }
        }
    }
    return nullptr;
}

void possibleValues(sudoku *a, bool *isLegal, int x, int y){
    for (int i = 0; i < DIMENSION; i++){
        if (a->board[x][i] != 0){
            isLegal[a->board[x][i] - 1] = false; 
        }
        if (a->board[i][y] != 0){
            isLegal[a->board[i][y] - 1] = false; 
        }
    }
}


void generateCandidate(sudoku *a, int *nC, int *C, int k, int x, int y){
    bool *isLegal = new bool[DIMENSION]; 
    

    for (int i = 0; i < DIMENSION; i++){
        isLegal[i] = true; 
    }

    possibleValues(a, isLegal, x, y);

    for (int i = 0; i < DIMENSION; i++){
        if (isLegal[i]){
            C[*nC] = i+1; 
            *nC = *nC +1;
        }
    }
    delete[] isLegal; 
}

void backtrack(sudoku *a, int k){
    if (isSolved(a)){
        a->finish = true; 
        printBoard(a); 
    }
    else{
        k++; 

        int *C = new int[DIMENSION]; 
        int *nC = new int; 

        int *move = findNextMove(a);

        if (move == nullptr) {
            delete[] C;
            delete nC;
            delete[] move;
            return;
        }

        int x = move[0];
        int y = move[1];

        generateCandidate(a, nC, C, k, x, y);


        for (int i = 0; i < *nC; i ++){
            a->board[x][y] = C[i]; 
            backtrack(a, k);

            if (a->finish)
                delete[] C; 
                delete nC; 
                delete [] move;
                return;   
            
            a->board[x][y] = 0;
        }
        delete nC; 
        delete[] C;
        delete[] move;

    }
}


int main(){
    sudoku *n = new sudoku; 

    n->board[1][2] = 1; 

    backtrack(n, 0); 

    delete n; 
}