#include "button.h"

class PlayButton : public Button {
public:
    PlayButton() = default;
    PlayButton(Coordinate position, Dimension size, sf::Color color, Dimension gridSize, Dimension cellSize);
    void action() override;
    void hover() override;
private:
    Dimension gridSize;
    Dimension cellSize;
};