#pragma once
#include "button.h"

class MenuButton : public Button {
public:
    MenuButton() = default;
    MenuButton(Coordinate position, Dimension size, sf::Color color);
    ~MenuButton() = default;
    void action() override;
    void hover() override;
private:
};