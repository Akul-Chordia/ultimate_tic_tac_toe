#pragma once

class tictactoe{
public:
    char grid[3][3];
    char winner;
    
    tictactoe(){
        this->winner = ' ';
        for (int i = 0; i < 9; i++){
            *(&grid[0][0] + i) = ' ';
        }
    }
    
    bool move(int i, int j, char player){
        if (grid[i][j] == ' ' && winner == ' '){
            grid[i][j] = player;
            return true;
        } else {
            return false;
        }
    }
    
    bool isfull(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (grid[i][j] == ' ') return false;
            }
        }
        return true;
    }
    
    bool checkwin(char player){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) winner = player;
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) winner = player;
            
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) winner = player;
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) winner = player;
        
        if (winner != ' '){
            return true;
        }
        return false;
    }
    
    void smallwinner(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                grid[i][j] = this->winner;
            }
        }
    }
    
    void drawsmallboard(){
        for (int i = 0; i < 3; i++){
            
            for (int j = 0; j < 3; j++){
                std::cout << grid[i][j];
            }
            std::cout << std::endl;
        }
        std::cout << "-----" << std::endl;
    }
};


class ultimate{
    std::vector<tictactoe> boards;
    char grid[3][3];
    char player;
    int board;
    
public:
    char winner;

    ultimate(){
        this->winner = ' ';
        this->player = 'X';
        for (int i = 0; i < 9; i++){
            *(&grid[0][0] + i) = ' ';
        }
        boards = std::vector<tictactoe>(9);
    }
    
    tictactoe getboard(int board){
        return this->boards[board];
    }
    
    char getplayer(){
        return this->player;
    }

    bool move(int board, int row, int col){
        if (row < 3 && row > -1 && col < 3 && col > -1){
            if (boards[board].move(row, col, player)){
                if (boards[board].checkwin(player)){
                    grid[board/3][board%3] = boards[board].winner;
                    boards[board].smallwinner();
                } else if (boards[board].isfull()){
                    grid[board/3][board%3] = 'N';
                }
                gameover();
                (player == 'X') ? player = 'O' : player = 'X';
                return true;
            }
        }
        return false;
    }

    bool gamewin(){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player){ winner = player; return true;}
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player){ winner = player; return true;}
            
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player){ winner = player; return true;}
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player){ winner = player; return true;}
        return false;
    }
    
    bool tie(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (grid[i][j] == ' ') return false;
            }
        }
        return true;
    }
    
    void gameover(){
        if (gamewin()){
            std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "\t\t\tPlayer " << this->winner << " wins!!" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            exit(0);
        }
        if (tie()){
            std::cout << std::endl << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
            std::cout << "\t\t\tIt's a tie -_-" << std::endl;
            std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~";
            exit(0);
        }
    }
    
    void print(){
        std::cout << "╔═══════╦═══════╦═══════╗\n";
        for (int i = 0; i < 3; i++) {
            for (int row = 0; row < 3; row++) {
                std::cout << "║ ";
                for (int j = 0; j < 3; j++) {
                    for (int col = 0; col < 3; col++) {
                        std::cout << boards[i * 3 + j].grid[row][col];
                        if (col < 2) std::cout << "|";
                    }
                    if (j < 2) std::cout << " ║ ";
                }
                std::cout << " ║\n";
            }
            if (i < 2){
                std::cout << "╠═══════╬═══════╬═══════╣\n";
            } else {
                std::cout << "╚═══════╩═══════╩═══════╝\n";
            }
        }
    }
};
