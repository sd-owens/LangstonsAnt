//
// Created by Steve Owens on 10/2/19.
//

#ifndef ANT_HPP
#define ANT_HPP

enum Direction { UP, RIGHT, DOWN, LEFT};

class Ant {
private:
    int xPos;
    int yPos;
    Direction direction;
public:
    Ant(int row, int col);

    int getXPos() const;

    void setXPos(int xPos);

    int getYPos() const;

    void setYPos(int yPos);

    Direction getDirection() const;

    void setDirection(Direction direction);

};


#endif //ANT_HPP
