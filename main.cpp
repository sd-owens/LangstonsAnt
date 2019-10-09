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
#include "AntGame.hpp"

/*
 * Summary: main function, creates new AntGame object on heap and calls play method.
 *          Frees memory on the heap once no longer required, assign nullptr to ag.
 * Param: none
 * Returns: int depending on exit state, 0 is successful.
 */

int main(){

     auto* ag = new AntGame();
     ag->play();

     delete ag;
     ag = nullptr;

    return 0;
}