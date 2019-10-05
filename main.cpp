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
#include "AntGame.hpp"

int main(){

    Ant* ant = new Ant(6,2);

    auto* b = new Board(16,64, ant);

    b->printBoard();

    auto* ag = new AntGame(b, ant, 50);

    ag->play();

    delete ag;
    delete ant;
    delete b;
    ag = nullptr;
//    b = nullptr;
//    ant = nullptr;



    return 0;
}