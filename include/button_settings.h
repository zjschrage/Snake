#include "button.h"

class SettingsButton : public Button {
public:
    SettingsButton() = default;
    SettingsButton(Coordinate position, Dimension size, sf::Color color);
    void action() override;
    void hover() override;
private:
};