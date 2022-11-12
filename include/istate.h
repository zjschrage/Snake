#pragma once
#include <SFML/Graphics.hpp>

class IState {
public:
    IState() = default;
    virtual ~IState() {}
    virtual void init() = 0;
    virtual void handleEvents(sf::RenderWindow& window) = 0;
    virtual void tick() = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual bool getRunning() = 0;
};