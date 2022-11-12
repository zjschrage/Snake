#include "button_menu.h"
#include "state_menu.h"
#include "state_singleton.h"
#include "dimension.h"
#include "constants.h"

MenuButton::MenuButton(Coordinate position, Dimension size, sf::Color color) 
    : Button(position, size, color, "Menu") {
    
}

void MenuButton::hover() {

}

void MenuButton::action() {
    auto state = std::make_unique<MenuState>(Dimension(SIZE_X, SIZE_Y), Dimension((float)DIM_X/SIZE_X, (float)DIM_Y/SIZE_Y));
    StateSingleton::setState(std::move(state));
}