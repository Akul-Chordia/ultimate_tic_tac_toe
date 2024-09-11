#pragma once
#include "tictactoe_class.h"

//approach 1 - pick the best move on that specific small board, pick random board if offered the choice

//int smallboardeval(tictactoe board) {
//    if (board.checkwin('O')) {
//        board.winner = ' ';
//        std::cout << 1;
//        return 1;
//    } else if (board.checkwin('X')) {
//        board.winner = ' ';
//        std::cout << -1;
//        return -1;
//    }
//    return 0;
//}

int win(const tictactoe *board){
    for (int i = 0; i < 3; i++) {
        if ((board -> grid[i][0] == board -> grid[i][1] && board -> grid[i][1] == board -> grid[i][2])){
            if (board -> grid[i][1] == 'O'){
                return 1;
            } else {
                return -1;
            }
        }
        if ((board -> grid[0][i] == board -> grid[1][i] && board -> grid[1][i] == board -> grid[2][i])){
            if (board -> grid[1][i] == 'O'){
                return 1;
            } else {
                return -1;
            }
        }
        if ((board -> grid[0][0] == board -> grid[1][1] && board -> grid[1][1] == board -> grid[2][2])){
            if (board -> grid[1][1] == 'O'){
                return 1;
            } else {
                return -1;
            }
        }
        if ((board -> grid[0][2] == board -> grid[1][1] && board -> grid[1][1] == board -> grid[2][0])){
            if (board -> grid[1][1] == 'O'){
                return 1;
            } else {
                return -1;
            }
        }
    }
    return 0;
}

int minmax(tictactoe temp, char player){
    int winner = win(&temp);
    
    if (winner != 0){
        if (player == 'O'){
            std::cout << winner;
            return winner;
        }
        std::cout << winner*-1;
        return winner*-1;
    }
    
    int row = -1, col = -1;
    int score = -2;

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (temp.grid[i][j] == ' '){
                temp.grid[i][j] = player;
                
                int currentScore = -minmax(temp, (player == 'O') ? 'X' : 'O');
                
                if (currentScore > score){
                    score = currentScore;
                    row = i;
                    col = j;
                }
                temp.grid[i][j] = ' ';
            }
        }
    }
    
    if (row == -1 || col == -1){
        return 0;
    };
    
    return score;
}
    

void AImove1(tictactoe temp, int* rowptr, int* colptr){
    int row = 1, col = 1;
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
}
