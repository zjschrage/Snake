#include <SFML/Graphics.hpp>
#include <stdio.h>
#include "dimension.h"
#include "singleton.h"
#include "state_menu.h"
#include "constants.h"
#include "game_variables.h"
#include "score_manager.h"
#include "audio.h"

void initManagers();

int main() {
    sf::RenderWindow window(sf::VideoMode(DIM_X, DIM_Y), TITLE);
    sf::Clock clock;
    window.setFramerateLimit(FPS);

    initManagers();

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

void initManagers() {
    auto gameVariables = std::make_unique<GameVariables>();
    Singleton<GameVariables>::set(std::move(gameVariables));

    auto scoreManager = std::make_unique<ScoreManager>();
    Singleton<ScoreManager>::set(std::move(scoreManager));

    auto audioManager = std::make_unique<Audio>();
    Singleton<Audio>::set(std::move(audioManager));

    auto state = std::make_unique<MenuState>();
    Singleton<IState>::set(std::move(state));
}