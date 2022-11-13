#include "button_settings.h"
#include "state_settings.h"
#include "state_singleton.h"

SettingsButton::SettingsButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Settings") {
    
}

void SettingsButton::hover() {

}

void SettingsButton::action() {
    auto state = std::make_unique<SettingsState>();
    StateSingleton::setState(std::move(state));
}