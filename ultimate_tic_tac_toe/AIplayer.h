#pragma once
#include "tictactoe_class.h"

//approach 1 - pick the best move on that specific small board, pick random board if offered the choice
int depth = 1;

int smallboardeval(tictactoe* board, char player){
    if (board -> checkwin('O')){
        return 100-depth;
    } else if (board -> checkwin('X')){
        return -100-depth;
    };
    return 0;
};

int AImove1(tictactoe temp, int board, int* rowptr, int* colptr, char player){
    depth++;
    bool moveFound = false;
    int bestScore = (player == 'O') ? -2 : 2;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (temp.grid[i][j] == ' '){
                temp.grid[i][j] = player;
                int moveScore = AImove1(temp, board, &i, &j, (player == 'O') ? 'X' : 'O');
                temp.grid[i][j] = ' ';
                
                if (player == 'O' && moveScore > bestScore) {
                    bestScore = moveScore;
                    *rowptr = i;
                    *colptr = j;
                    moveFound = true;
                }

                else if (player == 'X' && moveScore < bestScore) {
                    bestScore = moveScore;
                    *rowptr = i;
                    *colptr = j;
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






    

