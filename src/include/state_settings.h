#pragma once
#include <SFML/Graphics.hpp>
#include "istate.h"
#include "grid.h"
#include "snake.h"
#include "direction.h"
#include "state_game.h"
#include "button_menu.h"
#include "button_audio.h"
#include "button_wrap.h"
#include "button_gridsize.h"

class SettingsState : public IState {
public:
    SettingsState();
    ~SettingsState();
    void init() override;
    void handleEvents(sf::RenderWindow& window) override;
    void tick() override;
    void render(sf::RenderWindow& window) override;
    bool getRunning() override {return running;};

private:
    sf::Font font;
    sf::Text text;
    Button* menuButton;
    Button* audioButton;
    Button* wrapButton;
    ButtonSelector* gridsizeButton;
    bool running;

    void setupText();
    void setupBackButton();
};