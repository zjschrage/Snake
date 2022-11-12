#pragma once

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

void initDirectionMap();
Direction getDirection(int keyCode);
Direction changeDirection(const Direction& lastDirection, const Direction& newDirection);