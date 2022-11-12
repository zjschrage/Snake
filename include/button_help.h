#include "button.h"

class HelpButton : public Button {
public:
    HelpButton() = default;
    HelpButton(Coordinate position, Dimension size, sf::Color color);
    void action() override;
    void hover() override;
private:
};