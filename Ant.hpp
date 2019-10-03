//
// Created by Steve Owens on 10/2/19.
//

#ifndef ANT_HPP
#define ANT_HPP

enum Direction {UP, DOWN, LEFT, RIGHT};

class Ant {
private:
    int xPos;
    int yPos;
    Direction direction;
public:
    int getXPos() const {
        return xPos;
    }

    void setXPos(int xPos) {
        Ant::xPos = xPos;
    }

    int getYPos() const {
        return yPos;
    }

    void setYPos(int yPos) {
        Ant::yPos = yPos;
    }

    Direction getDirection() const {
        return direction;
    }

    void setDirection(Direction direction) {
        Ant::direction = direction;
    }
};


#endif //ANT_HPP
