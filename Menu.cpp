//
// Created by Steve Owens on 10/3/19.
//
#include <iostream>
#include "Menu.hpp"
#include "validInput.hpp"

void Menu::setup() {

    std::string inputMenu1, inputMenu2 {};
    int choice, rows, cols, steps, startRow, startColumn {};

    std::cout << "\n***************************************************\n";
    std::cout << "****************** Langston's Ant! ****************\n";
    std::cout << "***************************************************\n\n";
    //TODO make this relevant about Langstons Ant
    std::cout << "This program calculates the determinant of a user\n"
                 "defined matrix of either size 2 x 2 or 3 x 3.\n\n";

    std::cout << "Choose an option:\n";
    std::cout << "1. Start Langston's Ant Simulation\n2. Quit\n";

    do {

        getline(std::cin, inputMenu1);
        choice = validateInput(inputMenu1);

        //TODO add input validiation
        if(choice == 2) {

            break;

        } else if(choice == 1) {

            std::cout << "\nSome information is required before we begin the simulation:\n";
            std::cout << "[Please use positive integer values only!]\n";
            
            std::cout << "\nEnter number of rows for board:\n";
            getline(std::cin, inputMenu2);
            rows = validateInput(inputMenu2);
            
            std::cout << "\nEnter number of columns for board:\n";
            getline(std::cin, inputMenu2);
            cols = validateInput(inputMenu2);
            
            std::cout << "\nEnter numbers of steps for simulation:\n";
            getline(std::cin, inputMenu2);
            steps = validateInput(inputMenu2);
            
            std::cout << "\nEnter the starting row for the ant:\n";
            getline(std::cin, inputMenu2);
            startRow = validateInput(inputMenu2);
            
            std::cout << "\nEnter the starting column for the ant:\n";
            getline(std::cin, inputMenu2);
            startColumn = validateInput(inputMenu2);
            
            std::cout << rows << "\n" << cols << "\n"<< steps << "\n" << startRow << "\n" << startColumn;

            std::cout << "Let's begin the simulation!\n";

            break;
        }



    } while (true);
}
