/******************************************************************************
** Program name: Langston's Ant in C++
** Author: Steven Owens
** Date: 10/8/2019
** Description:  Langton's ant is a two-dimensional universal Turing machine
**               invented by Chris Langton in 1986.  It is a cellular automation
**               created on a black and white gameboard re-created in c++ using
**               in the console using the char '#' for black and ' ' for white.
**               The gameboard is implemented dynamically as a 2D array of
**               characters on the heap. The user is prompted by a console menu
**               for 5 integers (rows, columns, steps, ant starting row and ant
**               starting column) as inputs to instantiate the ant, board, and
**               antGame objects dynamically on the heap due the variability of
**               the object memory requirements.  Once the user is satisfied
**               with the setup, the simulations continues until the number of
**               steps reaches 0.  An additional replay feature has been added
**               to prompt the user for input and run the simulation again.
******************************************************************************/
#include "AntGame.hpp"

int main(){

     auto* ag = new AntGame();
     ag->play();

     delete ag;
     ag = nullptr;

    return 0;
}