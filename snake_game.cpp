#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "dimension.h"
#include "singleton.h"
#include "state_menu.h"
#include "constants.h"
#include "game_variables.h"
#include "score_manager.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(DIM_X, DIM_Y), TITLE);
    sf::Clock clock;
    window.setFramerateLimit(FPS);

    auto gameVariables = std::make_unique<GameVariables>();
    Singleton<GameVariables>::set(std::move(gameVariables));

    auto scoreManager = std::make_unique<ScoreManager>();
    Singleton<ScoreManager>::set(std::move(scoreManager));

    auto state = std::make_unique<MenuState>();
    Singleton<IState>::set(std::move(state));

    while (window.isOpen()) {

        Singleton<IState>::get().handleEvents(window);

        if (Singleton<IState>::get().getRunning() && clock.getElapsedTime().asSeconds() >= 1.0f/TICK_RENDER_SPEED) {
            Singleton<IState>::get().tick();
            Singleton<IState>::get().render(window);
            clock.restart();
        }

    }

    return 0;
}