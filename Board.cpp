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
#include <iostream>
#include "Board.hpp"
/*
 * Summary: board constructor which initializes member variables and dynamically allocates
 *          memory on the heap for the given size rows and columns.  The game board is a 2D
 *          array of char or rather a pointer to an array of char pointers which point
 *          to arrays of char.
 * Param: int row, int col rows and columns from input of the user in AntGame.
 * Param: Ant* ant - required due to implementation of printboard, the board must be able to
 *        determine the position of the ant.
 * Returns: N/A
 */
Board::Board(int row, int col, Ant* ant)
    : rows(row), columns(col), ant(ant){

    gameBoard = new char* [this->rows];
    for(int i = 0; i < this->rows; i++){
        gameBoard[i] = new char[this->columns];
    }
    initBoard();
}
/*
 * Summary: Custom destructor to handle iterating through arrays to free memory on heap.
 * Param: none
 * Returns: N/A
 */
Board::~Board() {
    delBoard();
}
/*
 * Summary: getter to return a char which is interpreted as the color of the game board square.
 * Param: int row, int col
 * Returns: char, either ' ' or '#'.
 */
char Board::getColor(int row, int column){
    return gameBoard[row][column];
}
/*
 * Summary: setter to change the color of the game board square based on ant movement.
 * Param: int row, int column, and char either ' ' or '#'.
 * Returns: void
 */
void Board::setColor(int row, int column, char symbol){
    gameBoard[row][column] = static_cast<char> (symbol);
}
// simple getter for number of rows.
int Board::getRows(){
    return this->rows;
}
// simple getter for number of columns.
int Board::getColumns(){
    return this->columns;
}
/*
 * Summary: method to initialize all char of the game board to ' '.
 * Param: none
 * Returns: void
 */
void Board::initBoard() {
    for(int y = 0; y < this->rows; y++) {

        for (int x = 0; x < this->columns; x++) {

            gameBoard[y][x] = ' ';
        }
    }
}
/*
 * Summary: Method to print the game board and also places the ant if the
 *          Ant occupies a given space by calling its getter for x and y.
 *          The method also places a border around the game board when
 *          printed to the console.
 * Param: none
 * Returns: void
 */
void Board::printBoard() {

    for(int i = 0; i <= this->columns + 1; i++) {
        std::cout << "-";
    }

    std::cout << "\n";
    for(int y = 0; y < this->rows; y++) {

        std::cout << "|";

        for(int x = 0; x < this->columns; x++){

            if(ant->getXPos() == x && ant->getYPos() == y) {
                std::cout << "*";
            } else {
                std::cout << static_cast<char>(gameBoard[y][x]);
            }
        }
        std::cout << "|\n";
    }
    for(int i = 0; i <= this->columns + 1; i++) {
        std::cout << "-";
    }
    std::cout << std::endl;
}
/*
 * Summary: Method to iterate through game board array to deallocate memory
 *          on the heap and set the gameBoard pointer to nullptr.
 * Param: none
 * Returns: void
 */
void Board::delBoard(){
    for(int i = 0; i < this->rows; i++){
        delete [] gameBoard[i];
    }
    delete[] gameBoard;
    gameBoard = nullptr;
}


