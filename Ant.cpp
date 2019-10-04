//
// Created by Steve Owens on 10/2/19.
//

#include "Ant.hpp"

Ant::Ant(int x, int y)
    : xPos(x), yPos(y){
    this->direction = UP;
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


