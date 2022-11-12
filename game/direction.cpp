#include <SFML/Graphics.hpp>
#include <map>
#include "direction.h"

static std::map<int, Direction> directionMapper;

void initDirectionMap() {
    directionMapper[sf::Keyboard::Key::W] = UP;
    directionMapper[sf::Keyboard::Key::A] = LEFT;
    directionMapper[sf::Keyboard::Key::S] = DOWN;
    directionMapper[sf::Keyboard::Key::D] = RIGHT;
}

Direction getDirection(int keyCode) {
    return directionMapper[keyCode];
}

Direction changeDirection(const Direction& newDirection, const Direction& lastDirection) {
    if (lastDirection == UP && newDirection == DOWN) return lastDirection;
    if (lastDirection == DOWN && newDirection == UP) return lastDirection;
    if (lastDirection == LEFT && newDirection == RIGHT) return lastDirection;
    if (lastDirection == RIGHT && newDirection == LEFT) return lastDirection;
    return newDirection;
}
