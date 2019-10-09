/**********************************************************************************
 * Program name: Langston's Ant
 * Author: Steven Owens
 * Date: 10/8/2019
 * Description:  Langston's ant is a two-dimensional universal Turing machine
 *               invented by Chris Langston in 1986.  It is a cellular automation
 *               created on a black and white game board re-created in c++ using
 *               in the console using the char '#' for black and ' ' for white.
 *               The game board implementation is a dynamically allocated 2D array
 *               of characters on the heap. The user is prompted by a console menu
 *               for 5 integers (rows, columns, steps, ant starting row and ant
 *               starting column) as inputs to setup the game parameters.  Once
 *               the user is satisfied with the setup, the simulations continues
 *               until the number of steps reaches 0.  An additional replay feature
 *               allows the user to run the simulation again.
 *********************************************************************************/
#include <iostream>
#include <string>
#include <vector>
#include "AntGame.hpp"
#include "Menu.hpp"
/*
 * Summary: AntGame constructor, contains all string data for game to be able to pass
 *          data to a generic menu class to prompt user for data.  Creates 3 pointers
 *          to objects and sets them to nullptr and initializes steps and turnNumber.
 *          These objects and private variables are set later in the setup() member
 *          method once user input is obtained.
 * Param: none
 * Returns: none.
 */
AntGame::AntGame(){
    this->board = nullptr;
    this->ant = nullptr;
    this->menu = nullptr;
    this->steps = 0;
    this->turnNumber = 0;
    this->title = "\n****************************************************\n"
                  "****************** Langston's Ant! *****************\n"
                  "****************************************************\n\n"
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
/*
 * Summary: Destructor to free memory allocated on heap for the board, ant and
 *          menu objects.  freeMem() is called by other functions due to various
 *          user menu options for replay, quit, and re-picking of input data.
 *          This destructor frees memory from the final run simulation of AntGame.
 * Param: none
 * Returns: none.
 */
AntGame::~AntGame() {
    freeMem();
}
/*
 * Summary: Logic for turning ant based on color of game board ('#' or ' ') and
 *          provided game rules.  If space is black ('#') ant turns left, if the
 *          space is white (' ') ant turns right.  The vacated space color is then
 *          swapped based on the color it was prior to ant movement.
 * Param: none
 * Returns: void.
 */
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
/*
 * Summary: Logic to redirect Ant.  Turns ant 180 degrees based on initial direction.
 * Param: none
 * Returns: void
 */

void AntGame::redirect() {

    Direction d = ant->getDirection();

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
/*
 * Summary: Logic to determine if Ant has reached a wall.  Valid positions are an
 *          Ant yPos from row 0 to input row(max) - 1 and an Ant xPos from column 0 to
 *          input column(max) - 1.
 * Param: int row from board class passed in from the AntGame::move() function.
 * Param: int column from board class passed in from the AntGame::move() function.
 * Returns: bool.
 */
bool AntGame::isWithinBounds(int row, int column) {

    return ((column >= 0 && column < board->getColumns()) && (row >= 0 && row < board->getRows()));
}
/*
 * Summary: Logic for ant movement. Gets the position and direction to determine the "case",
 *          checks if within bounds and moves ant if true.  calls turnAnt() function and then
 *          decrements steps if move was successful.
 * Param: none
 * Returns: bool, true for movement, false for failure to move.
 */
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
/*
 * Summary: Main game play logic and do-while loop.  Inits userChoice variable and calls
 *          setup() function which results in running first simulation.  Once complete
 *          program returns and prompts user if they want to play again by calling replay()
 *          If yes, then the memory from the first simulation is freed and setup is called
 *          again, otherwise the memory would be freed when called by the destructor.
 *          AbortStatus is unique in that if the user elects to immediately select 2 and
 *          exit the game without running sim on either iteration of while loop, it breaks
 *          and ends the loop thereby returning to main and calling the AntGame destructor.
 * Param: none
 * Returns: void
 */
void AntGame::play(){
    int userChoice{0};
    int abortStatus;

    do{
        abortStatus = setup(userChoice);

        if(abortStatus == -1){
            break;
        }
        userChoice = menu->replay();
        if (userChoice == 1) {
            freeMem();    // free 1st simulation memory and allow new objects to be created.
        }
    } while (userChoice != 2);

    std::cout << "GoodBye!" << std::endl;
}
/*
 * Summary: Logic to create a menu for user input and handle the returned data to finalize
 *          setup of the ant and board objects required for the simulation.  Passes the input
 *          prompts to the menu by reference and collects the return data in a vector which
 *          it then uses to instantiate the objects and set the final variable (steps) before
 *          calling the run() function.  The turnNumber variable exits to count up the steps
 *          as a header in the console to for each printing of the game board as a user aid.
 * Param: int option, which is 0 by default on the first run but can be returned as a
 *        1 from the menu->replay() function.
 * Returns: int, 0 is setup was completed successfully calling run() or -1 if the user
 *          aborted as discussion in the start() function.
 */
int AntGame::setup(int option) {
    std::vector<int> gameData;

    menu = new Menu(title,mainMenu,subMenu1,inputPrompts, startPrompt, replayPrompt);
    gameData = menu->display(option);

    if (!gameData.empty()) {
        // (0)rows, (1)cols, (2)steps, (3)startRow, (4)startColumn
        int rows = gameData.at(0);
        int columns = gameData.at(1);
        int stepsInput = gameData.at(2);
        int startRow = gameData.at(3);
        int startColumn = gameData.at(4);

        //error checking for ant startRow and startColumn
        if (startRow >= rows) {
            startRow = rows - 1;  // place within board and minus 1 for zero based array
        } else {
            startRow -= 1;  // subtracts one from user input for zero based array
        }
        //error checking for ant startRow and startColumn
        if (startColumn >= columns) {
            startColumn = rows - 1;  // place within board and minus 1 for zero based array
        } else {
            startColumn-= 1;  // subtracts one from user input for zero based array
        }

        ant = new Ant(startRow , startColumn) ;
        board = new Board(rows, columns, ant);

        this->steps = stepsInput;
        this->turnNumber = this->steps - (this->steps - 1);
        run();

        return 0;

    } else {
        freeMem();
        return -1;
    }
}
/*
 * Summary: While loop to handle movement of the Ant until steps = 0.  If move() returns
 *          false, the method calls the redirect() method to turn the ant 180 degree allowing
 *          the next call of move() to return true.
 * Param: none
 * Returns: void
 */
void AntGame::run() {

    while(this->steps != 0){

        std::cout << "Step " << std::to_string(this->turnNumber) << "\n";
        board->printBoard();
        if(!move()) {
            redirect();
        }
    }
}
/*
 * Summary: Method to free memory allocated on the heap as part of the AntGame class.
 *          This exists here vice only in the destructor because certain conditions exist
 *          such as early user termination of program or calling replay that require
 *          freeing memory before the destructor is called at the end of AntGame.
 * Param: none
 * Returns: void
 */
void AntGame::freeMem(){
    delete menu;
    delete board;
    delete ant;
    menu = nullptr;
    board = nullptr;
    ant = nullptr;
}
