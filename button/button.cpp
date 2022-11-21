#include "button.h"
#include "font.h"

Button::Button(Coordinate position, Dimension size, sf::Color color, std::string text) {
    this->body = sf::RectangleShape(sf::Vector2<float>(size.x, size.y));
    this->body.setPosition(position.x, position.y);
    this->body.setFillColor(color);
    sf::Font f;
    f.loadFromFile("fonts/PixeloidSans.ttf");
    this->font = f;
    sf::Text t(text, font, 60);
    t.setFillColor(sf::Color::Black);
    t.setPosition(position.x + (size.x - t.getGlobalBounds().width)/2, position.y);
    this->text = t;
}

bool Button::contains(Coordinate mouse) {
    return body.getGlobalBounds().contains(mouse.x, mouse.y);
}

void Button::render(sf::RenderWindow& window) {
    window.draw(body);
    window.draw(text);
}