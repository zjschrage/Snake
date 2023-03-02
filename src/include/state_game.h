#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"
#include "grid.h"
#include "snake.h"
#include "direction.h"
#include "state_game.h"

enum WrapStyle {
    EDGE_BARRIER,
    TOROIDAL
};

class GameState : public IState {
public:
    GameState(const Dimension& gridSize, const Dimension& cellSize, const Coordinate& snakeStart, WrapStyle wrapStype);
    void init() override;
    void handleEvents(sf::RenderWindow& window) override;
    void tick() override;
    void render(sf::RenderWindow& window) override;
    bool getRunning() override {return running;};

private:
    Grid g;
    Snake s;
    Dimension gridSize;
    Dimension cellSize;
    Direction tentativeDirection;
    Direction currentDirection;
    WrapStyle wrapStyle;
    bool running;

    void reset();
    bool checkNextLocation(Coordinate& next);
    void setNextStates(const Coordinate& next, const CellState& nextState);
    void updateCells();
    void stop();

};