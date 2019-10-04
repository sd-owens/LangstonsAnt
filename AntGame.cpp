//
// Created by Steve Owens on 10/4/19.
//

#include <ctime>
#include <cstdlib>
#include "AntGame.hpp"



AntGame::AntGame(Board* board, Ant* ant, int steps)
    : board(board), ant(ant), steps(steps){

}

int AntGame::getSteps() const {
    return steps;
}

bool AntGame::isWall() {

    if(ant->getDirection() == LEFT && ant->getXPos() == 0) { return true;}
    else if(ant->getDirection() == UP && ant->getYPos() == 0) {return true;}
    else if(ant->getDirection() == RIGHT && ant->getXPos() == board->getColumns()) {return true;}
    else if(ant->getDirection() == DOWN && ant->getYPos() == board->getRows()) {return true;}
    else {
        return false;
    }
}

void AntGame::turnAnt() {

    int x = ant->getXPos();
    int y = ant->getYPos();

    if (board->getColor(x, y) == '#') {

        switch (ant->getDirection()) {  // turn left
            case UP:
                ant->setDirection(LEFT);
                break;
            case LEFT:
                ant->setDirection(DOWN);
                break;
            case DOWN:
                ant->setDirection(RIGHT);
                break;
            case RIGHT:
                ant->setDirection(UP);
                break;
        }
        board->setColor(x, y, ' ');

    } else { // board color is white or ' '
        switch (ant->getDirection()) { // turn right
            case UP:
                ant->setDirection(LEFT);
            case LEFT:
                ant->setDirection(DOWN);
            case DOWN:
                ant->setDirection(RIGHT);
            case RIGHT:
                ant->setDirection(UP);
        }
        board->setColor(x, y, '#');

    }
}

int AntGame::redirect() {

    srand(time(nullptr));

    int randDir = (rand() % 4);  // results in a random value between 0 and 3

    ant->setDirection(static_cast<Direction >(randDir));

    return 0;
}

bool AntGame::move() {

    if(ant->getDirection() == UP && !isWall()) {
        ant->setYPos(ant->getYPos() - 1);
        turnAnt();
        this->steps--;
        return true;
    } else if (ant->getDirection() == RIGHT && !isWall()) {
        ant->setXPos(ant->getXPos() + 1);
        turnAnt();
        this->steps--;
        return true;
    } else if (ant->getDirection() == DOWN && !isWall()) {
        ant->setYPos(ant->getYPos() + 1);
        turnAnt();
        this->steps--;
        return true;
    } else if (ant->getDirection() == LEFT && !isWall()) {
        turnAnt();
        this->steps--;
        return true;
    } else {
        return false;
    }
}

void AntGame::play(){

    while(steps != 0){
        board->printBoard();
        if(!move()) {
            redirect();
        }
    }
}
