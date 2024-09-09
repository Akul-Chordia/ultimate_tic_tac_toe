#include <iostream>
#include <vector>

class tictactoe{
    char grid[3][3];
    
public:
    
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
            checkwin(player);
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
    
    void checkwin(char player){
        for (int i = 0; i < 3; i++) {
            if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) winner = player;
            if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player) winner = player;
            
        }
        if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) winner = player;
        if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) winner = player;
    };
    
    void print(){
        for (int i = 0; i < 3; i++){
            for (int j = 0; j < 3; j++){
                std::cout << grid[i][j];
                if (j<2){ std::cout << "|";};
            };
            if (i<2){std::cout << "\n_____\n";};
        };
        std::cout << "\n";
    };
};


//class ultimate{
//    std::vector<tictactoe> boards;
//    char big_grid[3][3];
//    char player;
//    int board;
//
//    ultimate(){
//
//    }
//
//    bool move(){
//
//    }
//
//    bool gamewin(){
//
//    }
//}


int main(){
    tictactoe game;
    int row, col;
    char player = 'X';
    while (true){
        game.print();
        std::cout << "Player " << player << "'s turn : ";
        std::cin >> row >> col;
        if (!game.move(row, col, player)){
            std::cout<<"Invalid Move\n";
        };
        game.checkwin(player);
        if (game.winner != ' ' || game.isfull()){
            game.print();
            return 0;
        }
        player == 'X'? player = 'O' : player = 'X';
    };
}
