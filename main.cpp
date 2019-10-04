/************************************************************************
** Program name: Langston's Ant
** Author: Steven Owens
** Date: 10/2/2019
** Description:  
************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Ant.hpp"
#include "Board.hpp"

int main(){

    std::cout << "Hello World\n";

    Ant* antPtr = new Ant(9, 8);

    Board* b = new Board(20, 40, antPtr);
    b->initBoard();
    b->printBoard();
//
//    std::cout << std::to_string(antPtr->getDirection()) + "\n"
//              << std::to_string(antPtr->getXPos()) + "\n"
//              << std::to_string(antPtr->getYPos()) + "\n";
//
//    antPtr->setDirection(DOWN);
//
//    std::cout << std::to_string(antPtr->getDirection()) + "\n"
//              << std::to_string(antPtr->getXPos()) + "\n"
//              << std::to_string(antPtr->getYPos()) + "\n";
//
//
//    b->delBoard();

    delete antPtr;
    antPtr = nullptr;

    delete b;
    b = nullptr;

//    Menu m;
//    m.setup();





    return 0;
}