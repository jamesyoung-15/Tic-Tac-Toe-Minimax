#ifndef AI_H
#define AI_H

#include "game.h"

struct BoardNode;


class BoardTree
{
    private:
        BoardNode* root {nullptr};

    public:
        /**
         * @brief Default empty constructor
         */
        BoardTree() = default;

        /**
         * @brief Initialize root using the provided board
         * 
         * @param board 
         */
        BoardTree(const Board& board);
        /**
         * @brief Destroy the Board Tree object and clear memory
         * 
         */
        ~BoardTree();

        // We don't need to copy tree in this case
        BoardTree(const BoardTree&) = delete;
        BoardTree& operator=(BoardTree&) = delete;

        /**
         * @brief Checks if root is empty
         * 
         * @return true empty
         * @return false not empty
         */
        bool isEmpty() const { return root == nullptr; }

        // Return a pointer to the subtree at the given coordinates. Build the tree if it is empty.
        /**
         * @brief Get the Sub Tree object, return a pointer to the subtree at the given coordinates. Build the tree if it is empty.
         * 
         * @param coords Coordinate to get subtree
         * @return BoardTree* the subtree at the given coordinates.
         */
        BoardTree* getSubTree(const BoardCoordinates& coords);

        // Calculate the best move by searching the tree up to depth moves ahead
        BoardOptimalMove getOptimalMove(const unsigned int depth);


        // For testing
        BoardNode* getRoot() const { return root; }


};
// Single board node that has the current board state and also a subtree for possible moves
struct BoardNode {
    const Board board; // Current board state
    BoardTree subTree[BOARD_SIZE][BOARD_SIZE]; // One sub-tree for each possible next move

    BoardNode(const Board& board): board(board) {}
    BoardNode(const BoardNode& node) = delete;
    BoardNode& operator=(const BoardNode& node) = delete;
};

#endif