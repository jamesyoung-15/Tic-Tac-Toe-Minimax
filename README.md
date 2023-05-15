# Tic-Tac-Toe with Minimax Algorithm
A 3x3 Tic-Tac-Toe game written in C++ with AI that plays the best move found with the [minimax alogrithm](https://en.wikipedia.org/wiki/Minimax). Inspired by assignment given in my coursework in COMP2012 (see the assignment description [here](./resources/pa3_instructions.pdf)).


## Minimax Algorithm Pseudocode
```
function minimax(node, depth, maximizingPlayer) is
    if depth = 0 or node is a terminal node then
        return the heuristic value of node
    if maximizingPlayer then
        value := −∞
        for each child of node do
            value := max(value, minimax(child, depth − 1, FALSE))
        return value
    else (* minimizing player *)
        value := +∞
        for each child of node do
            value := min(value, minimax(child, depth − 1, TRUE))
        return value
```

## Quick Usage
Only tested with Linux, but should work as long as system has C++ compiler.

1. Clone this repository
``` 
git clone 
 ```
 2. Compile the program with make.
 ```
make
 ```
 3. Run the script
 ```
 ./tic-tac-toe-game
 ``` 