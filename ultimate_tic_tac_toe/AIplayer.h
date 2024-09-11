#pragma once
#include "tictactoe_class.h"

//approach 1 - pick the best move on that specific small board, pick random board if offered the choice

int smallboardeval(tictactoe* board, int depth) {
    if (board->checkwin('O')) {
        return 100 - depth;
    } else if (board->checkwin('X')) {
        return -100 + depth;
    }
    return 0;
}

int AImove1(tictactoe temp, int board, int* rowptr, int* colptr, char player, int depth) {
    if (temp.checkwin('X') || temp.checkwin('O') || temp.isfull()) {
        return smallboardeval(&temp, depth);
    }

    int bestScore = (player == 'O') ? -1000 : 1000;
    int currentScore;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (temp.grid[i][j] == ' ') {
                temp.grid[i][j] = player;
                currentScore = -AImove1(temp, board, rowptr, colptr, (player == 'O') ? 'X' : 'O', depth + 1);
                temp.grid[i][j] = ' ';

                if (player == 'O'){
                    if (currentScore > bestScore) {
                        bestScore = currentScore;
                        if (depth == 0) {
                            *rowptr = i;
                            *colptr = j;
                        }
                    }
                } else {
                    if (currentScore < bestScore) {
                        bestScore = currentScore;
                    }
                }
            }
        }
    }
    return bestScore;
}



    

