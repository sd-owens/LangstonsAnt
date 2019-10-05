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

    Ant* ant = new Ant(24,8);

    auto* b = new Board(64,64, ant);

    b->printBoard();

    auto* ag = new AntGame(b, ant, 50);

    ag->play();

    delete ag;
    delete ant;
    delete b;



    return 0;
}