#include "button_selector.h"

ButtonSelector::ButtonSelector(Coordinate position, Dimension size, sf::Color color, std::string text) {
    this->up = sf::RectangleShape(sf::Vector2<float>(size.x, size.y*3/7));
    this->down = sf::RectangleShape(sf::Vector2<float>(size.x, size.y*3/7));
    this->up.setPosition(position.x, position.y);
    this->down.setPosition(position.x, position.y + size.y*4/7);
    this->up.setFillColor(color);
    this->down.setFillColor(color);
    sf::Font f;
    f.loadFromFile("fonts/PixeloidSans.ttf");
    this->font = f;
    sf::Text t(text, font, 60);
    t.setFillColor(sf::Color::White);
    t.setPosition(position.x + size.x + 20, position.y);
    this->text = t;
}

bool ButtonSelector::containsUp(Coordinate mouse) {
    return up.getGlobalBounds().contains(mouse.x, mouse.y);
}

bool ButtonSelector::containsDown(Coordinate mouse) {
    return down.getGlobalBounds().contains(mouse.x, mouse.y);
}

void ButtonSelector::render(sf::RenderWindow& window) {
    window.draw(up);
    window.draw(down);
    window.draw(text);
}