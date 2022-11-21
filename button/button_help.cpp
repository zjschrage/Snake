#include "button_help.h"
#include "state_help.h"
#include "singleton.h"
#include "istate.h"

HelpButton::HelpButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Help") {
    
}

void HelpButton::hover() {

}

void HelpButton::action() {
    auto state = std::make_unique<HelpState>();
    Singleton<IState>::set(std::move(state));
}