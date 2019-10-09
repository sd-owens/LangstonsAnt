/**********************************************************************************
 * Program name: Langston's Ant
 * Author: Steven Owens
 * Date: 10/8/2019
 * Description:  Langston's ant is a two-dimensional universal Turing machine
 *               invented by Chris Langston in 1986.  It is a cellular automation
 *               created on a black and white game board re-created in c++ using
 *               in the console using the char '#' for black and ' ' for white.
 *               The game board implementation is a dynamically allocated 2D array
 *               of characters on the heap. The user is prompted by a console menu
 *               for 5 integers (rows, columns, steps, ant starting row and ant
 *               starting column) as inputs to setup the game parameters.  Once
 *               the user is satisfied with the setup, the simulations continues
 *               until the number of steps reaches 0.  An additional replay feature
 *               allows the user to run the simulation again.
 *********************************************************************************/

#ifndef BOARD_HPP
#define BOARD_HPP

#include "Ant.hpp"

class Board {
private:
    int rows;
    int columns;
    Ant* ant;
    char** gameBoard;
public:
    Board(int row, int col, Ant* ant);
    ~Board();
    char getColor(int row, int column);
    void setColor(int row, int column, char symbol);
    int getRows();
    int getColumns();
    void initBoard();
    void printBoard();
    void delBoard();
};

#endif //BOARD_HPP
