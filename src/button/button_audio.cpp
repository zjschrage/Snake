#include "button_audio.h"
#include "singleton.h"
#include "game_variables.h"
#include "constants.h"

AudioButton::AudioButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Audio") {
    this->on = Singleton<GameVariables>::get().audio;
    if (on) body.setFillColor(sf::Color(BUTTON_COLOR));
    else body.setFillColor(sf::Color(BUTTON_COLOR_OFF));

    this->text.setPosition(position.x + size.x + 20, position.y);
    this->text.setFillColor(sf::Color::White);
}

void AudioButton::hover() {

}

void AudioButton::action() {
    on = !on;
    if (on) body.setFillColor(sf::Color(BUTTON_COLOR));
    else body.setFillColor(sf::Color(BUTTON_COLOR_OFF));
    Singleton<GameVariables>::get().audio = on;
}