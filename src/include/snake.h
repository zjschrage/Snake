#pragma once
#include <vector>
#include "coordinate.h"
#include "direction.h"

class Snake {
public:
    typedef std::vector<Coordinate> SnakeBody;
    Snake() = default;
    Snake(const Coordinate& c);
    ~Snake() {}
    const SnakeBody& getSnake() {return snake;};
    const Coordinate& getLocation() {return location;};
    int getLength() {return length;};
    Coordinate nextLocation(const Direction& lastDirection);
    void moveHead(const Coordinate& c);
    void moveTail();

private:
    SnakeBody snake;
    Coordinate location;
    int length;

};