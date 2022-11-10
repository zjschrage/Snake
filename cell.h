#pragma once
#include <SFML/Graphics.hpp>
#include "coordinate.h"
#include "dimension.h"

enum CellState {
    EMPTY,
    SNAKE_HEAD,
    SNAKE_BODY,
    FOOD
};

class Cell {
public:
    Cell(const Coordinate& c, const Dimension& d);
    ~Cell();
    const CellState& getState() {return state;};
    void changeState(const CellState& s);
    const sf::RectangleShape& getGraphicCell();

private:
    sf::RectangleShape cell;
    CellState state;
};