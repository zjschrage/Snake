#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"
#include "grid.h"
#include "snake.h"
#include "direction.h"
#include "state_game.h"
#include "button_menu.h"

class HelpState : public IState {
public:
    HelpState();
    ~HelpState();
    void init() override;
    void handleEvents(sf::RenderWindow& window) override;
    void tick() override;
    void render(sf::RenderWindow& window) override;
    bool getRunning() override {return running;};

private:
    sf::Font font;
    sf::Text text;
    Button* menuButton;
    bool running;

    void setupText();
    void setupBackButton();
};