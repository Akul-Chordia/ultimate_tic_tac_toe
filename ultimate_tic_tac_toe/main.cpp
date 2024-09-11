#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "tictactoe_class.h"
#include "AIplayer.h"


int scin(const std::string& prompt) {
    int number;
    while (true) {
        std::cout << prompt;
        std::cin >> number;

        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Invalid input. Please enter an integer.\n";
        } else {
            std::cin.ignore(1000, '\n');
            if (number == 69){
                exit(69);
            }
            return number;
        }
    }
}


int main(){
    ultimate game;
    int row, col;
    int board = -1;
    int AImode = -1;
    char multiplayer;
    
    srand((int)time(0));
    
    while (true){
        std::cout << "Do you want to play in multiplayer mode? (y/n) : ";
        std::cin >> multiplayer;
        if (multiplayer == 'n' || multiplayer == 'N'){
            AImode = scin("Enter AI level (0-3) : ");
            break;
        } else if (multiplayer == 'y' || multiplayer == 'Y') {
            break;
        } else {
            continue;
        }
    }
    game.print();
    
    while (true){
        
        
        if (game.getboard(board).isfull() || game.getboard(board).winner != ' '){
            board = -1;
        }
        
        std::cout << "Player " << game.getplayer() << "'s turn : \n";
        
        if (board == -1){
            board = scin("Enter Board (0-8) : ");
        }
        
        row = scin("Enter row (0-2) : ");
        col = scin("Enter col (0-2) : ");
        
        if (!game.move(board, row, col)){
            std::cout<<"\nInvalid Move!!!\n";
            continue;
        }
        
        game.print();
        
        board = row*3 + col;
        //board = 1;
        game.gameover();
        
        if (game.getboard(board).isfull() || game.getboard(board).winner != ' '){
            board = -1;
        }
        
        if (AImode == 0){
            while (true){
                if (board == -1){
                    board = rand() % 9;
                }
                //board = 1;
                AImove1(game.getboard(board), board ,&row ,&col ,'O', 0);
                std::cout << row << col << std::endl;
                if (game.move(board, row, col)){
                    board = row*3 + col;
                    //board = 1;
                    break;
                }
            }
        }
    }
}
