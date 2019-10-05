//
// Created by Steve Owens on 10/3/19.
//
#include <iostream>
#include "Menu.hpp"
#include "validInput.hpp"
#include "Ant.hpp"
#include "Board.hpp"
#include "AntGame.hpp"

Menu::~Menu(){
    delete antGame;
    delete board;
    delete ant;
}

void Menu::setup() {

    std::string inputMenu1, inputMenu2 {};
    int choice {};

    // [0]rows, [1]cols, [2]steps, [3]startRow, [4]startColumn
    int data[5];
    int data_size {5};
    int count{0};

    std::string title {
            "\n***************************************************\n"
            "****************** Langston's Ant! ****************\n"
            "***************************************************\n\n"
            "Langton's ant is a two-dimensional universal Turing\n"
            "machine with a very simple set of rules but complex\n"
            "emergent behavior. It was invented by Chris Langton\n"
            "in 1986 and runs on a square lattice of black and\n"
            "white cells.\n"
    };

    std::string mainMenu {
            "\nChoose an option:\n"
            "1. Start Langston's Ant Simulation\n2. Quit\n"
    };
    std::string subMenu1 {
            "\nSome information is required before we begin the simulation:\n"
            "[Please use positive integer values only!]\n"
    };

    std::string inputPrompts[] = {
            "\nEnter number of rows for board:\n",
            "\nEnter number of columns for board:\n",
            "\nEnter numbers of steps for simulation:\n",
            "\nEnter the starting row for the ant:\n",
            "\nEnter the starting column for the ant:\n"
    };

    int inputPrompts_size {5};

    do {

        if(count == 0){
            std::cout << title;
            std::cout << mainMenu;
        }


        getline(std::cin, inputMenu1);
        choice = validateInput(inputMenu1);

        if(choice == 2) {
            break;

        } else if(choice == 1) {

            for (int i = 0; i < inputPrompts_size; i++){
                std::cout << inputPrompts[i];
                getline(std::cin, inputMenu2);
                data[i] = validateInput(inputMenu2);
            }
        }
        count++;
        std::cout << "Let's begin the simulation!\n";
        start(data, data_size);
        std::cout << "\nSimulation Complete!\n\nPlay Again?\n";
        std::cout << mainMenu;
    } while (true);
}

void Menu::start(int* data, int data_size) {

    for(int i = 0; i < data_size; i++) {
        std::cout << data[i] << std::endl;
    }

    ant = new Ant(data[3],data[4]);
    board = new Board(data[0], data[1], ant);

    antGame = new AntGame(board, ant, data[2]);

    antGame->play();

}
