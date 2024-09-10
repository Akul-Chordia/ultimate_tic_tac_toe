#include "tictactoe_class.h"

//approach 1 - pick the best move on that specific small board, pick random board if offered the choice
int smallboardeval(tictactoe* board, char player){
    if (board -> checkwin('O')){
        return 100;
    } else if (board -> checkwin('X')){
        return -100;
    };
    return 0;
};

int basicminmax(tictactoe* ptr, int* iptr, int* jptr, char player){
    tictactoe temp = *ptr;
    
    bool moveFound = false;
    int bestScore = (player == 'O') ? -2 : 2;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (temp.grid[i][j] == ' '){
                temp.grid[i][j] = player;
                int moveScore = basicminmax(&temp, &i, &j, (player == 'O') ? 'X' : 'O');
                temp.grid[i][j] = ' ';
                
                if (player == 'O' && moveScore > bestScore) {
                    bestScore = moveScore;
                    *iptr = i;
                    *jptr = j;
                    moveFound = true;
                }

                else if (player == 'X' && moveScore < bestScore) {
                    bestScore = moveScore;
                    *iptr = i;
                    *jptr = j;
                    moveFound = true;
                }
            };
        };
    };
    if (!moveFound) {
            return 0;
        }

        return bestScore;
};








    
