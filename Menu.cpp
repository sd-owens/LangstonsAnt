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
#include <vector>
#include "Menu.hpp"
#include "validInput.hpp"

/* static variable to track the number of times a Menu object is created for use
 * in user replay feature. only need to know if the call is greater than once.
 */
int Menu::count;
/*
 * Summary: Menu constructor which takes numerous input parameters passed by reference
 *          to prevent duplicating strings in memory.  Each input param is initialized
 *          to its respective private instance variable.
 * Param: 5 strings for menu Prompts and one vector of strings for data prompts. By passing
 *        in params in this manner I have attempted to encapsulate the Menu class for future
 *        use a generic user input Menu.
 * Returns: N/A
 */
Menu::Menu(std::string &title, std::string &mainMenu, std::string &subMenu1, std::vector<std::string> &inputPrompts, std::string &startPrompt, std::string &relayPrompt){
    this->title = title;
    this->mainMenu = mainMenu;
    this->subMenu1 = subMenu1;
    this->inputPrompts = inputPrompts;
    this->startPrompt = startPrompt;
    this->replayPrompt = relayPrompt;
}
/*
 * Summary: Primary method for user input, handles all logic and console prompts to facilitate user input
 *          and validation of entry of only positive integer values.  Ensuring that the Ant startRow and
 *          startColumn are within the bound of the game board is handled by the AntGame class once returned
 *          as a vector.
 * Param: int choice which by default is 0 from hpp definition, this allows passing in a value for the replay
 *        functionality.
 * Returns: std::vector<int> which are the 5 integers required for instantiation of objects in AntGame.
 */
std::vector<int> Menu::display(int choice) {

    std::string inputMenu1, inputMenu2, inputMenu3 {};
    choice = choice;

    // (0)rows, (1)cols, (2)steps, (3)startRow, (4)startColumn
    std::vector<int> gameData;

    do {
        if(count == 0) {
            std::cout << title;
            std::cout << mainMenu;

            while(choice != 1 && choice != 2) {
                getline(std::cin, inputMenu1);
                choice = validateInput(inputMenu1);
                if(choice != 1 && choice != 2){
                    std::cerr << "Pick 1 or 2!\n";
                }
            }
        }

        if(choice == 2) {
            gameData.clear();  //used in early abort criteria to ensure objects are not created.
            return gameData;

        } else if(choice == 1 || choice == 3) {

            if(count == 0) {
                std::cout << subMenu1;
            }

            for (int i = 0; i < inputPrompts.size(); i++){
                std::cout << inputPrompts[i];
                getline(std::cin, inputMenu2);
                gameData.push_back(validateInput(inputMenu2));
            }
        }
        count++;
        choice = 0;  // reset choice to 0 for next while loop check.
        std::cout << startPrompt;

        while(choice != 1 && choice != 2 && choice != 3) {
            getline(std::cin, inputMenu3);
            choice = validateInput(inputMenu3);
            if(choice != 1 && choice != 2 && choice != 3){
                std::cerr << "Pick 1, 2, or 3!\n";
            }
        }

        if(choice == 1) {
            return gameData;
        }

    } while (true);
}
/*
 * Summary: Replay function which displays a replayMenu to the user and captures their choice.
 * Param: none
 * Returns: int which is a 1 or 2 by the menu.
 */
int Menu::replay() {

    std::string inputMenu4 {};
    int choice {};

    std::cout << replayPrompt;
    while(choice != 1 && choice != 2) {
        getline(std::cin, inputMenu4);
        choice = validateInput(inputMenu4);
        if(choice != 1 && choice != 2){
            std::cerr << "Pick 1 or 2!\n";
        }
    }

    return choice;
}



