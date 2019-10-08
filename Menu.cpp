//
// Created by Steve Owens on 10/3/19.
//
#include <iostream>
#include <vector>
#include "Menu.hpp"
#include "validInput.hpp"

Menu::Menu(std::string &title, std::string &mainMenu, std::string &subMenu1, std::vector<std::string> &inputPrompts, std::string &startPrompt, std::string &relayPrompt){
    this->title = title;
    this->mainMenu = mainMenu;
    this->subMenu1 = subMenu1;
    this->inputPrompts = inputPrompts;
    this->startPrompt = startPrompt;
    this->replayPrompt = relayPrompt;
}

std::vector<int> Menu::display() {

    std::string inputMenu1, inputMenu2 {};
    int choice {};

    // [0]rows, [1]cols, [2]steps, [3]startRow, [4]startColumn
    std::vector<int> gameData;
    int count{0};

    do {
        if(count == 0) {
            std::cout << title;
            std::cout << mainMenu;

            getline(std::cin, inputMenu1);
            choice = validateInput(inputMenu1);
        }

        if(choice == 2) {
            gameData.clear();
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
        std::cout << startPrompt;

        getline(std::cin, inputMenu1);
        choice = validateInput(inputMenu1);

        if(choice == 1) {
            return gameData;
        }

    } while (true);
}

void Menu::replay() {

    std::string inputMenu3 {};
    int choice {};

    std::cout << replayPrompt;
    getline(std::cin, inputMenu3);
    choice = validateInput(inputMenu3);

    if (choice == 1){
        display();
    }
}



