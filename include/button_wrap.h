#pragma once
#include "button.h"
// #include "button_toggle.h"
#include "state_game.h"

class WrapButton : public Button {
public:
    WrapButton() = default;
    WrapButton(Coordinate position, Dimension size, sf::Color color);
    ~WrapButton() = default;
    void action() override;
    void hover() override;
private:
    WrapStyle wrap;
};