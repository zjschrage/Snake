#pragma once
#include <SFML/Graphics.hpp>
#include "coordinate.h"
#include "dimension.h"

class Button {
public:
    Button() = default;
    //virtual ~Button();
    Button(Coordinate position, Dimension size, sf::Color color, std::string text);
    bool contains(Coordinate mouse);
    void render(sf::RenderWindow& window);
    const sf::RectangleShape& getBody() {return body;}
    virtual void action() = 0;
    virtual void hover() = 0;
private:
    sf::RectangleShape body;
    sf::Font font;
    sf::Text text;
};