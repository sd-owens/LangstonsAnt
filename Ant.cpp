//
// Created by Steve Owens on 10/2/19.
//

#include <cstdlib>
#include <ctime>
#include "Ant.hpp"

Ant::Ant(int x, int y)
    : xPos(x), yPos(y){

    srand(time(nullptr));

    int randDir = (rand() % 4);  // results in a random value between 0 and 3

    this->direction = static_cast<Direction >(randDir);
}

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


