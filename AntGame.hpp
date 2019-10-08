//
// Created by Steve Owens on 10/4/19.
//

#ifndef ANTGAME_HPP
#define ANTGAME_HPP

#include <vector>
#include <string>
#include "Board.hpp"
#include "Menu.hpp"

class AntGame {
private:
    std::string title;
    std::string mainMenu;
    std::string subMenu1;
    std::string startPrompt;
    std::string replayPrompt;
    std::vector<std::string> inputPrompts;
    Board* board;
    Ant* ant;
    Menu* menu;
    int steps;
    int turnNumber;

public:
    AntGame();
    ~AntGame();
    bool isWithinBounds(int row, int column);
    void turnAnt();
    void redirect();
    bool move();
    void play();
    void run();
};


#endif //ANTGAME_HPP
