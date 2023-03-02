#include "button_wrap.h"
#include "singleton.h"
#include "game_variables.h"
#include "constants.h"

WrapButton::WrapButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Wrap") {
    this->wrap = Singleton<GameVariables>::get().wrapStyle; 
    if (wrap == TOROIDAL) body.setFillColor(sf::Color(BUTTON_COLOR));
    else body.setFillColor(sf::Color(BUTTON_COLOR_OFF));

    this->text.setPosition(position.x + size.x + 20, position.y);
    this->text.setFillColor(sf::Color::White);
}

void WrapButton::hover() {

}

void WrapButton::action() {
    if (wrap == EDGE_BARRIER) wrap = TOROIDAL;
    else wrap = EDGE_BARRIER;
    if (wrap == TOROIDAL) body.setFillColor(sf::Color(BUTTON_COLOR));
    else body.setFillColor(sf::Color(BUTTON_COLOR_OFF));
    Singleton<GameVariables>::get().wrapStyle = wrap;
}