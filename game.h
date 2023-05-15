#ifndef GAME_H
#define GAME_H

#include <iostream>
#include "math.h"

const int BOARD_SIZE = 3;
// const int XWIN_SCORE = 1000;
// const int OWIN_SCORE = -1000;

// Single cell of a 3x3 board
enum Cell
{
    EMPTY = 0,
    X = 1,
    O = 2,
};

// Board Coordinate struct
struct BoardCoordinates
{
    int row, col;
    BoardCoordinates(int row, int col) : row(row), col(col) {}
    bool isValid() const { return row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE; }
};

// optimal move struct
struct BoardOptimalMove {
    BoardCoordinates coords;

    // Default constructor returns an "illegal" move
    BoardOptimalMove(): coords(BoardCoordinates(-1, -1)) {}
    BoardOptimalMove(const BoardCoordinates& coords):  coords(coords) {}
};

// main game board class
class Board
{
    private:
        // int board[3][3]={0};
        Cell curPlayer;
        int id;
        Cell boardCells[BOARD_SIZE][BOARD_SIZE];
        int score;

    public:
        /**
         * @brief Construct a new empty Board object, initializes boardCells to empty
         * 
         */
        Board();

        /**
        * @brief Checks if board is full
        * @return true 
        * @return false 
        */
        bool boardFull();

        /**
        * @brief Check if either players have won (horizontal, vertical, and diagonal check)
        * @return true if over
        * @return false if not
        */
        bool checkWin();

        /**
         * @brief Plays a move based on passed coordinate, checks if it is a valid move.
         * 
         * @param coordinate The coordinate to play 
         * @return true if valid coordinate
         * @return false if not valid coordinate
         */
        bool makeMove(const BoardCoordinates& coordinate);
        
        /**
         * @brief Prints the board state
         * 
         */
        void printBoard();

        /**
         * @brief Returns the current player of the game.
         * @return X current player is X
         * @return O current player is O
         */
         Cell getCurrentPlayer() const;
};


#endif