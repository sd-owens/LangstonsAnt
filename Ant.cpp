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

#include <cstdlib>
#include <ctime>
#include "Ant.hpp"

/*
 * Summary: Ant Constructor, sets xPos and yPos member variables to input params.
 *          Creates a random int between 0 and 3 and cast it to an enum Direction
 *          to set the direction member variable.
 * Param: int row
 * Param: int column
 * Returns: none
 */
Ant::Ant(int row, int col)
    : xPos(col), yPos(row){

    srand(time(nullptr));  // seeds random function with system time.

    int randDir = (rand() % 4);  // results in a random value between 0 and 3

    this->direction = static_cast<Direction >(randDir);
}

// standard getters and setters below for all private member variables.

int Ant::getXPos() const {
    return xPos;
}

void Ant::setXPos(int xPos) {
    Ant::xPos = xPos;
}

int Ant::getYPos() const {
    return yPos;
}

void Ant::setYPos(int yPos) {
    Ant::yPos = yPos;
}

Direction Ant::getDirection() const {
    return direction;
}

void Ant::setDirection(Direction direction) {
    Ant::direction = direction;
}


