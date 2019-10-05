//
// Created by Steve Owens on 10/2/19.
//
#include <iostream>
#include "Board.hpp"

Board::Board(int row, int col, Ant* ant)
    : rows(row), columns(col), ant(ant){

    gameBoard = new char* [this->rows];
    for(int i = 0; i < this->rows; i++){
        gameBoard[i] = new char[this->columns];
    }
    initBoard();
}

Board::~Board() {
    delBoard();
    delete ant;
    ant = nullptr;
    std::cout << "Destructor called";
}

char Board::getColor(int row, int column){
    return gameBoard[row][column];
}
//TODO possible cause of error
void Board::setColor(int row, int column, char symbol){
    gameBoard[row][column] = static_cast<char> (symbol);
}

int Board::getRows(){
    return this->rows;
}
int Board::getColumns(){
    return this->columns;
}

void Board::initBoard() {
    for(int y = 0; y < this->rows; y++) {

        for (int x = 0; x < this->columns; x++) {

            gameBoard[y][x] = ' ';
        }
    }
}

void Board::printBoard() {

    std::cout << "\n";
    for(int i = 0; i <= this->columns; i++) {
        std::cout << "--";
    }

    std::cout << "\n";
    for(int y = 0; y < this->rows; y++) {

        std::cout << "|";

        for(int x = 0; x < this->columns; x++){

            if(ant->getXPos() == x && ant->getYPos() == y) {
                std::cout << "* ";
            } else {
                std::cout << static_cast<char>(gameBoard[y][x]);
                std::cout << ' ';
            }
        }
        std::cout << "|\n";
    }
    for(int i = 0; i <= this->columns; i++) {
        std::cout << "--";
    }
    std::cout << std::endl;
}

void Board::delBoard(){
    for(int i = 0; i < this->rows; i++){
        delete [] gameBoard[i];
    }
    delete[] gameBoard;
    gameBoard = nullptr;
}


