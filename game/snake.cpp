#include "snake.h"

Snake::Snake(const Coordinate& c) {
    this->location = c;
    this->snake.push_back(c);
    this->length = 1;
}

Coordinate Snake::nextLocation(const Direction& lastDirection) {
    Coordinate newHead(location);
    switch(lastDirection) {
        case UP:
            newHead.y -= 1;
            break;
        case DOWN:
            newHead.y += 1;
            break;
        case LEFT:
            newHead.x -= 1 ;
            break;
        case RIGHT:
            newHead.x += 1;
            break;
    }
    return newHead;
}

void Snake::moveHead(const Coordinate& newHead) {
    location = newHead;
    snake.insert(snake.begin(), newHead);
}

void Snake::moveTail() {
    snake.erase(snake.begin() + snake.size() - 1);
}