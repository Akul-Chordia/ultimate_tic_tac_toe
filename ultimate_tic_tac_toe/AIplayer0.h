#pragma once
#include "tictactoe_class.h"

//pick the best move on that specific small board
//pick random board if offered the choice
//pick random move if board is empty

int AI_0_eval(char (&grid)[3][3], char player) {
    tictactoe* temp = new tictactoe();
    
    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            temp -> grid[i][j] = grid[i][j];
        }
    }
    
    if (temp -> checkwin('O')){
        delete temp;
        return 1;
    } else if (temp -> checkwin('X')){
        delete temp;
        return -1;
    }
    delete temp;
    return 0;
    
}

int AI_0_minimax(char (&board)[3][3], char player) {
    int winner = AI_0_eval(board, player);
    
    if(winner != 0){
        return -1;
    }

    bool move = false;
    int score = -2;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            
            if (board[i][j] == ' ') {
                
                board[i][j] = player;
                
                int thisScore = -AI_0_minimax(board, (player == 'O') ? 'X' : 'O');
                
                if (thisScore > score) {
                    score = thisScore;
                    move = true;
                }
                board[i][j] = ' ';
            }
        }
    }
    if (!move){
        return 0;
    }
    
    return score;
}


int AI_move_0(char (&board)[3][3], int* rowptr, int* colptr) {
    
    bool is_empty = true;
    
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (board[i][j] != ' '){
                is_empty = false;
            }
        }
    }
    
    if (is_empty){
        *rowptr = rand() % 3;
        *colptr = rand() % 3;
        return 0;
    }

    int row = -1, col = -1;
    int score = -2;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++){
            if (board[i][j] == ' ') {
                board[i][j] = 'O';
                
                int tempScore = -AI_0_minimax(board, 'X');
                board[i][j] = ' ';
                
                if (tempScore > score) {
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
