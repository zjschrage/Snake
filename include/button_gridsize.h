#pragma once
#include "button.h"
#include "button_selector.h"

class GridSizeButton : public ButtonSelector {
public:
    GridSizeButton() = default;
    GridSizeButton(Coordinate position, Dimension size, sf::Color color);
    ~GridSizeButton() = default;
    void action(int delta) override;
    void hover() override;
};