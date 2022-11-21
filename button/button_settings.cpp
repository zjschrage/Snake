#include "button_settings.h"
#include "state_settings.h"
#include "singleton.h"
#include "istate.h"

SettingsButton::SettingsButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Settings") {
    
}

void SettingsButton::hover() {

}

void SettingsButton::action() {
    auto state = std::make_unique<SettingsState>();
    Singleton<IState>::set(std::move(state));
}