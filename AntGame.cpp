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

AntGame::AntGame(Board* &board, Ant* &ant, int steps)
    : board(board), ant(ant), steps(steps){

}

AntGame::~AntGame(){
    delete board;
    board = nullptr;
    delete ant;
    ant = nullptr;
}

void AntGame::turnAnt() {

    int col = ant->getXPos();
    int row = ant->getYPos();
    Direction d = ant->getDirection();

    if (board->getColor(row, col) == '#') {

        switch (d) {  // turn left
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
        board->setColor(row, col, ' ');

    } else if (board->getColor(row, col) == ' ') { // board color is white or ' '
        switch (d) { // turn right
            case UP:
                ant->setDirection(RIGHT);
                break;
            case LEFT:
                ant->setDirection(UP);
                break;
            case DOWN:
                ant->setDirection(LEFT);
                break;
            case RIGHT:
                ant->setDirection(DOWN);
                break;
        }
        board->setColor(row, col, '#');

    }
}

void AntGame::redirect() {

    Direction d = ant->getDirection();
//    srand(time(nullptr));
//
//    int randDir = (rand() % 4);  // results in a random value between 0 and 3
//
//    ant->setDirection(static_cast<Direction >(randDir));
    switch (d) {  // turn left
        case UP:
            ant->setDirection(DOWN);
            break;
        case LEFT:
            ant->setDirection(RIGHT);
            break;
        case DOWN:
            ant->setDirection(UP);
            break;
        case RIGHT:
            ant->setDirection(LEFT);
            break;
    }
}

bool AntGame::isWithinBounds(int row, int column) {

    return ((column >= 0 && column <= board->getColumns()) && (row >= 0 && row <= board->getRows()));
}

bool AntGame::move() {

    int yPos = ant->getYPos();
    int xPos = ant->getXPos();

    switch (ant->getDirection()) {
        case UP:
            if (isWithinBounds(yPos - 1, xPos)) {
                ant->setYPos(yPos - 1);
            } else {
                return false;
            }
            break;
        case RIGHT:
            if (isWithinBounds(yPos, xPos + 1)) {
                ant->setXPos(xPos + 1);
            } else {
                return false;
            }
            break;
        case DOWN:
            if (isWithinBounds(yPos + 1, xPos)) {
                ant->setYPos(yPos + 1);
            } else {
                return false;
            }
            break;
        case LEFT:
            if (isWithinBounds(yPos, xPos - 1)) {
                ant->setXPos(xPos - 1);
            } else {
                return false;
            }
            break;
    }
    turnAnt();
    steps--;
    return true;
}

void AntGame::play(){

    while(steps != 0){
//        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + milliseconds(100));
        board->printBoard();
        if(!move()) {
            redirect();
        }
    }
}
