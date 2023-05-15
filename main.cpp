#include "game.h"
#include <iostream>
#include <string>

const int depth = 5;

int main()
{
    // create board instance
    Board board;
    printf("Welcome to my Tic-Tac-Toe game.\n\n");
    
    int choice = -500;
    while(choice!=1 && choice!=2 && choice!=-1)
    {
        std::cout<<"Enter 1 to play against AI, 2 to play against another human, -1 to quit: " << std::endl;
        std::cin>>choice;
    }
    if(choice==-1)
    {
        return 0;
    }
    else if(choice==1)
    {
        std::cout<<"AI"<<std::endl;
    }
    else if(choice==2)
    {
        board.printBoard();
        std::string currentPlayer = "X";

        // main game
        while(true)
        {
            // change players, for printing
            if(board.getCurrentPlayer()==X)
                currentPlayer = "X";
            else if (board.getCurrentPlayer()==O)
                currentPlayer = "O";
            
            std::cout<< "Current player to play is: " << currentPlayer << std::endl;
            // init variables for play movement
            int row=-500;
            int column=-500;
            
            // while loop breaks when player enters a valid row
            while (row<-1 || row>BOARD_SIZE)
            {
                printf("Type a row to place move (0-2) or -1 to quit: \n");    
                std::cin>> row;
            }
            // if -1, then end game
            if(row==-1)
                break;
            // while loop breaks when player enters a valid column
            while (column<-1 || column>BOARD_SIZE)
            {
                printf("Type a column to place move (0-2) or -1 to quit: \n");    
                std::cin>> column;
            }
            // if -1, then end game
            if(column==-1)
                break;

            // make the move that the player played
            board.makeMove(BoardCoordinates{row,column});
            board.printBoard();
            
            // check if the board is full and no wins found, then draw
            if(board.boardFull() && !board.checkWin())
            {
                printf("Draw!\n");
                break;
            }
            // if board not full but win found, end game
            else if(!board.boardFull() && board.checkWin())
            {
                std::cout<< "Player " << currentPlayer << " Wins!" << std::endl;
                break;
            }
            // if board full and win found, end game
            else if (board.boardFull() && board.checkWin())
            {
                std::cout<< "Player " << currentPlayer << " Wins!" << std::endl;
                break;
            }

        }
    }
    return 0;
}