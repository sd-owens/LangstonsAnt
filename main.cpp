/************************************************************************
** Program name: Langston's Ant
** Author: Steven Owens
** Date: 10/2/2019
** Description:  
************************************************************************/
#include <iostream>
#include "Menu.hpp"
#include "Ant.hpp"

int main(){

    std::cout << "Hello World";

    Ant* antPtr = new Ant(9, 8);

    std::cout << std::to_string(antPtr->getDirection()) + "\n"
              << std::to_string(antPtr->getXPos()) + "\n"
              << std::to_string(antPtr->getYPos()) + "\n";

    antPtr->setDirection(DOWN);

    std::cout << std::to_string(antPtr->getDirection()) + "\n"
              << std::to_string(antPtr->getXPos()) + "\n"
              << std::to_string(antPtr->getYPos()) + "\n";


    delete antPtr;
    antPtr = nullptr;

//    Menu m;
//    m.setup();



    return 0;
}