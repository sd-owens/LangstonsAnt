//
// Created by Steve Owens on 10/3/19.
//

#ifndef MENU_HPP
#define MENU_HPP


#include "Ant.hpp"
#include "Board.hpp"
#include "AntGame.hpp"

class Menu {
private:
    Ant* ant;
    Board* board;
    AntGame* antGame;
public:
    ~Menu();
    void run();
    void start(int* data, int data_size);
};


#endif //MENU_HPP
