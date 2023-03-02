#pragma once
#include "button.h"

class PlayButton : public Button {
public:
    PlayButton() = default;
    PlayButton(Coordinate position, Dimension size, sf::Color color);
    ~PlayButton() = default;
    void action() override;
    void hover() override;
};