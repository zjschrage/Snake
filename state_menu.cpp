#include "state_menu.h"
#include "state_singleton.h"

MenuState::MenuState(const Dimension& gridSize, const Dimension& cellSize) {
    this->gridSize = gridSize;
    this->cellSize = cellSize;
    this->running = true;
    this->init();
}

void MenuState::init() {
    
}

void MenuState::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            auto state = std::make_unique<GameState>(Dimension(cellSize.x, cellSize.y), Dimension((float)gridSize.x/cellSize.x, (float)gridSize.y/cellSize.y), Coordinate(12, 12), TOROIDAL);
            StateSingleton::setState(std::move(state));
        }
    }
}

void MenuState::tick() {
    
}

void MenuState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(sf::RectangleShape(sf::Vector2<float>(200, 100)));
    window.display();
}