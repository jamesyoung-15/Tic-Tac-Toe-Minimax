#include "ai.h"


BoardTree::BoardTree(const Board& board)
{
    root = new BoardNode{board};
}

BoardTree::~BoardTree()
{
    delete root; // recursive
}

BoardTree *BoardTree::getSubTree(const BoardCoordinates &coords)
{
    // If subtree is empty, try to build it
    if (root->subTree[coords.row][coords.col].isEmpty()) 
    {
        Board nextBoard = Board(root->board);
        if (nextBoard.makeMove(BoardCoordinates(coords.row, coords.col))) 
        {
            root->subTree[coords.row][coords.col].root = new BoardNode(nextBoard);
        }
    }
    return &(root->subTree[coords.row][coords.col]);
}

BoardOptimalMove BoardTree::getOptimalMove(const unsigned int depth)
{
    // If tree is empty, returns an illegal move
    if (isEmpty()) 
    {
        return BoardOptimalMove();
    }

    // return score and random coordinate if game won, game finished with no winner, or 0 depth passed
    if(depth==0 || root->board.checkWin() || root->board.boardFull())
        return BoardOptimalMove(root->board.getBoardScore(),BoardCoordinates(1,1));

    // Else, we find the estimated score and optimal move of this node by calculating the score of each children node
    // Player X is trying to maximize the score, so the estimated score is the maximum of children scores
    // Vice versa, player O is trying to minimize the score
    int estimatedScore=0;
    if(root->board.getCurrentPlayer()==X)
        estimatedScore=-WIN_SCORE-1000;
    else if(root->board.getCurrentPlayer()==O)
        estimatedScore=WIN_SCORE+1000;
    BoardOptimalMove bestMove;


   // otherwise do as usual
        // for each subtree, build tree if empty, if move illegal subtree move to next subtree
    for(int i=0;i<BOARD_SIZE;i++)
    {
        for(int j=0;j<BOARD_SIZE;j++)
        {
            BoardCoordinates coords = BoardCoordinates(i,j);;
            // build the subtree if it is empty
            if(root->subTree[i][j].isEmpty())
            {
                getSubTree(coords);
            }
            BoardOptimalMove childMove = root->subTree[i][j].getOptimalMove(depth-1);
            if (childMove.score == ILLEGAL) 
            {
                // If the move is illegal, the subtree corresponds to an invalid move/board, simply skip to the next subtree
                continue;
            }
            if((root->board.getCurrentPlayer()==X && childMove.score>estimatedScore) || (root->board.getCurrentPlayer()==O && childMove.score<estimatedScore))
            {
                estimatedScore = childMove.score;
                bestMove = BoardOptimalMove(estimatedScore,coords);
            }

        }
    }

    return bestMove;
}