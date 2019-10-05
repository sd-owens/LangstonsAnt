//
// Created by Steve Owens on 10/4/19.
//

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "AntGame.hpp"

/* Implemented time delay functionality between ant move commands to allow user to view
   console output.  Adapted from post by user "barnes53" on 20120317 from
   https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program */

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

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

void AntGame::redirect() {

    srand(time(nullptr));

    int randDir = (rand() % 4);  // results in a random value between 0 and 3

    ant->setDirection(static_cast<Direction >(randDir));

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
//        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + milliseconds(500));
        board->printBoard();
        if(!move()) {
            redirect();
        }
    }
}
