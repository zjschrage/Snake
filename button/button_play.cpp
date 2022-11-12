#include "button_play.h"
#include "state_game.h"
#include "state_singleton.h"

PlayButton::PlayButton(Coordinate position, Dimension size, sf::Color color, Dimension gridSize, Dimension cellSize) 
    : Button(position, size, color, "Play"), gridSize(gridSize), cellSize(cellSize) {
    
}

void PlayButton::hover() {

}

void PlayButton::action() {
    auto state = std::make_unique<GameState>(Dimension(gridSize.x, gridSize.y), Dimension(cellSize.x, cellSize.y), Coordinate(12, 12), TOROIDAL);
    StateSingleton::setState(std::move(state));
}