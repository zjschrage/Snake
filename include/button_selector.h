#pragma once
#include <SFML/Graphics.hpp>
#include "coordinate.h"
#include "dimension.h"

class ButtonSelector {
public:
    ButtonSelector() = default;
    ButtonSelector(Coordinate position, Dimension size, sf::Color color, std::string text);
    bool contains(Coordinate mouse);
    void render(sf::RenderWindow& window);
    const sf::RectangleShape& getUp() {return up;}
    const sf::RectangleShape& getDown() {return down;}
    virtual void action() = 0;
    virtual void hover() = 0;
protected:
    sf::RectangleShape up;
    sf::RectangleShape down;
    sf::Font font;
    sf::Text text;
};