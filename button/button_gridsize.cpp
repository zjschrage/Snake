#include "button_gridsize.h"
#include "singleton.h"
#include "game_variables.h"
#include "constants.h"
#include <string>

GridSizeButton::GridSizeButton(Coordinate position, Dimension size, sf::Color color) 
    : ButtonSelector(position, size, color, std::to_string(Singleton<GameVariables>::get().gridSize)) {
    this->text.setPosition(position.x + size.x + 20, position.y);
    this->text.setFillColor(sf::Color::White);
}

void GridSizeButton::hover() {

}

void GridSizeButton::action(int delta) {
    int gridSize = Singleton<GameVariables>::get().gridSize;
    if (delta < 0 && gridSize <= 15) return;
    if (delta > 0 && gridSize >= 50) return;
    Singleton<GameVariables>::get().gridSize += delta;
    text.setString(std::to_string(Singleton<GameVariables>::get().gridSize));
}