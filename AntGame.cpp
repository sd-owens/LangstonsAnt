//
// Created by Steve Owens on 10/4/19.
//

#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <chrono>
#include <thread>
#include "AntGame.hpp"
#include "Menu.hpp"

/* Implemented time delay functionality between ant move commands to allow user to view
   console output.  Adapted from post by user "barnes53" on 20120317 from
   https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program */

using namespace std::this_thread; // sleep_for, sleep_until
using namespace std::chrono; // nanoseconds, system_clock, seconds

AntGame::AntGame(){
    this->board = nullptr;
    this->ant = nullptr;
    this->menu = nullptr;
    this->steps = 0;
    this->turnNumber = 0;
    this->title = "\n***************************************************\n"
                  "****************** Langston's Ant! ****************\n"
                  "***************************************************\n\n"
                  "Langston's ant is a two-dimensional universal Turing\n"
                  "machine with a very simple set of rules but complex\n"
                  "emergent behavior. It was invented by Chris Langston\n"
                  "in 1986 and runs on a square lattice of black and\n"
                  "white cells.\n";

    this->mainMenu = "\nChoose an option:\n"
                     "1. Start Langston's Ant Simulation\n2. Quit\n";

    this->subMenu1 = "\nSome information is required before we begin the simulation:\n";

    this->inputPrompts = {"\nEnter number of rows for board (positive integers only):\n",
                     "\nEnter number of columns for board (positive integers only):\n",
                     "\nEnter numbers of steps for simulation (positive integers only):\n",
                     "\nEnter the starting row for the ant (first row is '1'):\n",
                     "\nEnter the starting column for the ant (first column is '1'):\n"};

    this->startPrompt = "\nReady to begin the simulation?\n"
                        "1. Start\n2. Quit\n3. Change inputs\n";

    this->replayPrompt = "\nSimulation Complete!\n"
                         "\nPlay Again?\n"
                         "1. Play again\n2. Quit\n";

//    std::unordered_map<std::string, std::string> game;
//    game.

}
AntGame::~AntGame() {
    delete menu;
    delete board;
    delete ant;
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

    return ((column >= 0 && column < board->getColumns()) && (row >= 0 && row < board->getRows()));
}

bool AntGame::move() {

    int yPos = ant->getYPos();  //row
    int xPos = ant->getXPos();  //column

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
    ++turnNumber;
    return true;
}

/* Implemented time delay functionality between ant move commands to allow user to view
   console output.  Adapted from post by user "barnes53" on 20120317 from
   https://stackoverflow.com/questions/158585/how-do-you-add-a-timed-delay-to-a-c-program */
void AntGame::play(){
    int userChoice{0};

    do{
        setup(userChoice);
        userChoice = menu->replay();
        if (userChoice == 1) {
            delete menu;
            delete board;
            delete ant;
        }
    } while (userChoice != 2);

    std::cout << "GoodBye!" << std::endl;
}

void AntGame::setup(int option) {
    std::vector<int> gameData;

    menu = new Menu(title,mainMenu,subMenu1,inputPrompts, startPrompt, replayPrompt);
    gameData = menu->display(option);

    if (!gameData.empty()) {
        // subtracts one from user input for zero based arrays
        ant = new Ant(gameData.at(3) - 1 , gameData.at(4) - 1) ;
        board = new Board(gameData.at(0), gameData.at(1), ant);
        this->steps = gameData.at(2);
        this->turnNumber = this->steps - (this->steps - 1);
        run();
    }
}

void AntGame::run() {

    while(this->steps != 0){

//        sleep_for(nanoseconds(10));
//        sleep_until(system_clock::now() + milliseconds(100));
        std::cout << "Step " << std::to_string(this->turnNumber) << "\n";
        board->printBoard();
        if(!move()) {
            redirect();
        }
    }
}
