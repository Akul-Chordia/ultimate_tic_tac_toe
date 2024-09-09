#include <iostream>
#include <vector>

class tictactoe{
    
public:
    char grid[3][3];
    char winner;
    
    tictactoe(){
        this -> winner = ' ';
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
    };
    
    bool isfull(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                if (grid[i][j] == ' ') return false;
            };
        };
        return true;
    };
    
    char checkwin(char player){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) winner = player;
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) winner = player;
            
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) winner = player;
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) winner = player;
        
        return winner;
    };
};


class ultimate{
    std::vector<tictactoe> boards;
    char grid[3][3];
    int board;
    
public:
    char winner;

    ultimate(){
        this -> winner = ' ';
        for (int i = 0; i < 9; i++){
            *(&grid[0][0] + i) = ' ';
        }
        boards = std::vector<tictactoe>(9);
    };

    bool move(int board, int row, int col, char player){
        if (boards[board].move(row, col, player)){
            grid[board/3][board%3] = boards[board].checkwin(player);
            return true;
        } else {
            return false;
        };
    };


    void gamewin(char player){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) winner = player;
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) winner = player;
            
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) winner = player;
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) winner = player;
        
        if (winner != ' '){
            std::cout << "Player " << winner << " wins!!";
            exit(0);
        }
    };
    
    void print(){
        for (int i = 0; i < 3; i++) {
            for (int row = 0; row < 3; row++) {
                for (int j = 0; j < 3; j++) {
                    for (int col = 0; col < 3; col++) {
                        std::cout << boards[i * 3 + j].grid[row][col];
                        if (col < 2) std::cout << "||";
                    }
                    std::cout << "  ";
                }
                std::cout << "\n";
            }
            if (i < 2) std::cout << "-----  -----  -----\n";
        };
    };
};


int main(){
    ultimate game;
    int board, row, col;
    board = -1;
    char player = 'X';
    while (true){
        game.print();
        std::cout << "Player " << player << "'s turn : \n";
        if (board == -1){
            std::cout << "Enter Board 0-8 : ";
            std::cin >> board;
        };
        std::cout << "Enter row (0-2) : ";
        std::cin >> row;
        std::cout << "Enter col (0-2) : ";
        std::cin >> col;
        if (!game.move(board, row, col, player)){
            std::cout<<"Invalid Move\n";
            continue;
        };
        board = row*3 + col;
        game.gamewin(player);
        (player == 'X') ? player = 'O' : player = 'X';
    };
}
