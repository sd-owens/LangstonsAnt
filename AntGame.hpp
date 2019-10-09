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

#ifndef ANTGAME_HPP
#define ANTGAME_HPP

#include <vector>
#include <string>
#include "Board.hpp"
#include "Menu.hpp"

class AntGame {
private:
    std::string title;
    std::string mainMenu;
    std::string subMenu1;
    std::string startPrompt;
    std::string replayPrompt;
    std::vector<std::string> inputPrompts;
    Board* board;
    Ant* ant;
    Menu* menu;
    int steps;
    int turnNumber;

public:
    AntGame();
    ~AntGame();
    bool isWithinBounds(int row, int column);
    void turnAnt();
    void redirect();
    bool move();
    void play();
    int setup(int option = 0);
    void run();
    void freeMem();
};


#endif //ANTGAME_HPP
