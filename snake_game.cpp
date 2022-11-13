#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include "grid.h"
#include "snake.h"
#include "direction.h"
#include "dimension.h"
#include "state_singleton.h"
#include "singleton.h"
#include "istate.h"
#include "state_game.h"
#include "state_menu.h"
#include "constants.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(DIM_X, DIM_Y), TITLE);
    sf::Clock clock;
    window.setFramerateLimit(FPS);

    auto state = std::make_unique<MenuState>(Dimension(SIZE_X, SIZE_Y), Dimension((float)DIM_X/SIZE_X, (float)DIM_Y/SIZE_Y));
    StateSingleton::setState(std::move(state));
    //Singleton<IState>::set(std::move(state));

    while (window.isOpen()) {

        StateSingleton::getState().handleEvents(window);
        
        if (StateSingleton::getState().getRunning() && clock.getElapsedTime().asSeconds() >= 1.0f/TICK_RENDER_SPEED) {
            StateSingleton::getState().tick();
            StateSingleton::getState().render(window);
            clock.restart();
        }

    }

    return 0;
}