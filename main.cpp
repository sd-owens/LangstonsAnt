/************************************************************************
** Program name: Langston's Ant
** Author: Steven Owens
** Date: 10/2/2019
** Description:  
************************************************************************/
#include "AntGame.hpp"

int main(){

     auto* ag = new AntGame();
     ag->play();

     delete ag;
     ag = nullptr;

    return 0;
}