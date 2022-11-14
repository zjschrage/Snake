#pragma once
#include "button.h"

class AudioButton : public Button {
public:
    AudioButton() = default;
    AudioButton(Coordinate position, Dimension size, sf::Color color);
    ~AudioButton() = default;
    void action() override;
    void hover() override;
private:
    bool on;
};