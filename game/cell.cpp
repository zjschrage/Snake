#include "cell.h"

Cell::Cell(const Coordinate& c, const Dimension& d) {
    this->cell = sf::RectangleShape(sf::Vector2<float>(d.x, d.y));
    this->cell.setFillColor(sf::Color::Black);
    this->cell.setPosition(c.x * d.x, c.y * d.y);
    this->state = EMPTY;
}

void Cell::changeState(const CellState& s) {
    this->state = s;
    switch (s) {
        case EMPTY:
            cell.setFillColor(sf::Color::Black);
            break;
        case SNAKE_HEAD:
            cell.setFillColor(sf::Color::Magenta);
            break;
        case SNAKE_BODY:
            cell.setFillColor(sf::Color::Cyan);
            break;
        case FOOD:
            cell.setFillColor(sf::Color::Green);
            break;
    }
}

const sf::RectangleShape& Cell::getGraphicCell() {
    return cell;
}