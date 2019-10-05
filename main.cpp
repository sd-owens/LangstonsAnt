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

    Ant* ant = new Ant(2,2);

    Board* b = new Board(10,20, ant);

    b->printBoard();

    AntGame* ag = new AntGame(b, ant, 30);

    ag->play();

    delete ag;
    ag = nullptr;

    delete b;
    b= nullptr;
    delete ant;
    ant = nullptr;

    return 0;
}