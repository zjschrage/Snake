#include "button_menu.h"
#include "state_menu.h"
#include "dimension.h"
#include "constants.h"
#include "singleton.h"
#include "istate.h"

MenuButton::MenuButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Menu") {
    
}

void MenuButton::hover() {

}

void MenuButton::action() {
    auto state = std::make_unique<MenuState>();
    Singleton<IState>::set(std::move(state));
}