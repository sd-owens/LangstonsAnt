//
// Created by Steve Owens on 10/2/19.
//

#ifndef BOARD_HPP
#define BOARD_HPP


#include "Ant.hpp"

class Board {
private:
    int rows;
    int columns;
    Ant* ant;
    char** gameBoard;
public:
    Board(int row, int col, Ant* &ant);
    ~Board();
    char getColor(int row, int column);
    void setColor(int row, int column, char symbol);
    int getRows();
    int getColumns();
    void initBoard();
    void printBoard();
    void delBoard();
};


#endif //BOARD_HPP
