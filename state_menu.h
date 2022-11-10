#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"
#include "grid.h"
#include "snake.h"
#include "direction.h"
#include "state_game.h"

class MenuState : public IState {
public:
    MenuState(const Dimension& gridSize, const Dimension& cellSize);
    void init() override;
    void handleEvents(sf::RenderWindow& window) override;
    void tick() override;
    void render(sf::RenderWindow& window) override;
    bool getRunning() override {return running;};

private:
    Dimension gridSize;
    Dimension cellSize;
    bool running;

};