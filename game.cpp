#include "game.h"
#include <iostream>

Board::Board()
{
    id = 0;
    curPlayer = X;
    score = 0;
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            boardCells[i][j] = EMPTY;
        }
    }
}

bool Board::boardFull()
{
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(boardCells[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}

bool Board::checkWin()
{

    /* Check for winners */

    // check match vertically
    for(int row=0;row<BOARD_SIZE;row++)
    {
        int rowCounter=0;
        Cell previousCell = boardCells[row][0];
        if(previousCell!=EMPTY)
            rowCounter=1;
        for (int column=1;column<BOARD_SIZE;column++)
        {
            if(previousCell==boardCells[row][column] && boardCells[row][column]!=EMPTY)
                rowCounter++;
            previousCell = boardCells[row][column];
        }
        if(rowCounter==BOARD_SIZE)
            return true;
    }
    // check for match horizontally
    for(int column=0;column<BOARD_SIZE;column++)
    {
        int columnCounter=0;
        Cell previousCell = boardCells[0][column];
        if(previousCell!=EMPTY)
            columnCounter=1;
        for (int row=1;row<BOARD_SIZE;row++)
        {
            if(previousCell==boardCells[row][column] && boardCells[row][column]!=EMPTY)
                columnCounter++;
            previousCell = boardCells[row][column];
        }
        if(columnCounter==BOARD_SIZE)
            return true;
    }

    // check for match diagonal left to right
    int leftRightCheck =0;
    Cell firstCell = boardCells[0][0];
    if(firstCell!=EMPTY)
        leftRightCheck++;
    for(int i=1;i<BOARD_SIZE;i++)
    {
        if(firstCell==boardCells[i][i] && boardCells[i][i]!=EMPTY)
            leftRightCheck++;
    }
    if(leftRightCheck==BOARD_SIZE)
        return true;

    // check for match diagonal right to left
    int rightLeftCheck =0;
    Cell lastCell = boardCells[0][BOARD_SIZE-1];
    if(lastCell!=EMPTY)
        rightLeftCheck++;
    for(int i=1;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            if(i+j==BOARD_SIZE-1)
            {
                if(boardCells[i][j]==lastCell)
                {
                    rightLeftCheck++;
                }
            }
        }
    }
    if(rightLeftCheck==BOARD_SIZE)
        return true;

    // otherwise return false
    return false;
}

bool Board::makeMove(const BoardCoordinates& coordinate)
{
        // if coordinates not valid
    if(coordinate.isValid()!=1)
        return false;

    // if cell filled
    if(boardCells[coordinate.row][coordinate.col]!=EMPTY)
        return false;

    // if no players
    if(curPlayer==EMPTY)
        return false;

    // update boardCells
    boardCells[coordinate.row][coordinate.col] = curPlayer;

    // update player
    if(curPlayer==X)
        curPlayer = O;
    else if(curPlayer==O)
        curPlayer = X;
    
    // update id
    id = 0;
    //for each cell 
    for (int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {   
            unsigned long long cellValue = 0;     
            //  cellValue = 0 if cell is empty, 1 if cell is X, 2 if cell is 0;
            if(boardCells[i][j] == EMPTY)
                cellValue = 0;
            else if(boardCells[i][j]==X)
                cellValue = 1;
            else if(boardCells[i][j]==O)
                cellValue = 2;
            id += cellValue * (pow(3,i*BOARD_SIZE+j));
        }
    }


    return true;
}

void Board::printBoard()
{
    for (int i=0;i<BOARD_SIZE;i++)
    {
        std::cout<<"----";
        if(i==BOARD_SIZE-1)
            std::cout<<"-";
    }
    printf("\n");
    for (int i=0;i<BOARD_SIZE;i++)
    {
        std::cout<<"| ";
        for (int j=0;j<BOARD_SIZE;j++)
        {
            if(boardCells[i][j]==EMPTY)
                std::cout<<" ";
            else if(boardCells[i][j]==X)
                std::cout<<"X";
            else if(boardCells[i][j]==O)
                std::cout<<"O";
            if(j!=BOARD_SIZE-1)
                std::cout<<" | ";
        }
        std::cout<<" |"<<std::endl;
        for (int i=0;i<BOARD_SIZE;i++)
        {
            std::cout<<"----";
            if(i==BOARD_SIZE-1)
                std::cout<<"-";
        }
        printf("\n");
    }
}


Cell Board::getCurrentPlayer() const
{
    return curPlayer;
}