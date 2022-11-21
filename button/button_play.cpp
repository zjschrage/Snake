#include "button_play.h"
#include "state_game.h"
#include "singleton.h"
#include "istate.h"
#include "game_variables.h"
#include "constants.h"
#include <iostream>

PlayButton::PlayButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Play") {
    
}

void PlayButton::hover() {

}

void PlayButton::action() {
    int gSize = Singleton<GameVariables>::get().gridSize;
    auto state = std::make_unique<GameState>(Dimension(gSize, gSize), Dimension((float)DIM_X/gSize, (float)DIM_Y/gSize), Coordinate(12, 12), Singleton<GameVariables>::get().wrapStyle);
    Singleton<IState>::set(std::move(state));
}