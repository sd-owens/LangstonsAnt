//
// Created by Steve Owens on 10/4/19.
//

#ifndef ANTGAME_HPP
#define ANTGAME_HPP


#include "Board.hpp"

class AntGame {
private:
    Board* board;
    Ant* ant;
    int steps;
public:
    AntGame(Board* board, Ant* ant, int steps);
    ~AntGame();
    bool isWithinBounds(int row, int column);
    void turnAnt();
    void redirect();
    bool move();
    void play();
};


#endif //ANTGAME_HPP
