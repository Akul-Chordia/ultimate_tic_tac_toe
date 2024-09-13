#pragma once
#include "tictactoe_class.h"

//approach 1 - pick the best move on that specific small board, pick random board if offered the choice

int smallboardeval(tictactoe *board) {
    if (board->checkwin('O')) {
        return 1;
    } else if (board->checkwin('X')) {
        return -1;
    }
    return 0;
}

int minmax(tictactoe temp, char player){
    
    int winner = smallboardeval(&temp);
    
    if (winner != 0){
        return -1;
    }
    
    int row = -1, col = -1;
    int score = -2;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (temp.grid[i][j] == ' '){
                temp.grid[i][j] = player;
                
                
                int currentScore = -minmax(temp, (player == 'O') ? 'X' : 'O');
                std::cout << currentScore << std::endl;
                
                if (currentScore > score){
                    score = currentScore;
                    row = i;
                    col = j;
                }
                temp.grid[i][j] = ' ';
                temp.winner = ' ';
            }
        }
    }
    
    if (row == -1 && col == -1){
        return 0;
    };
    
    return score;
}
    

int AImove1(tictactoe temp, int* rowptr, int* colptr){
    int row = -1, col = -1;
    int score = -2;
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (temp.grid[i][j] == ' '){
                temp.grid[i][j] = 'O';

                
                int tempScore = -minmax(temp, 'X');
                
                if (tempScore > score){
                    score = tempScore;
                    row = i;
                    col = j;
                }
            }
        }
    }

    *rowptr = row;
    *colptr = col;
    return 0;
}
