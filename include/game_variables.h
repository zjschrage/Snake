#pragma once
#include "state_game.h"

class GameVariables {
public:
    int gridSize;
    WrapStyle wrapStyle;
    bool audio;

    GameVariables() {
        gridSize = 25;
        wrapStyle = TOROIDAL;
        audio = true;
    }
};