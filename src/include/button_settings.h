#pragma once
#include "button.h"

class SettingsButton : public Button {
public:
    SettingsButton() = default;
    SettingsButton(Coordinate position, Dimension size, sf::Color color);
    ~SettingsButton() = default;
    void action() override;
    void hover() override;
private:
};