#include "state_menu.h"
#include "state_singleton.h"

MenuState::MenuState(const Dimension& gridSize, const Dimension& cellSize) {
    this->gridSize = gridSize;
    this->cellSize = cellSize;
    this->fontColor = 0xff;
    this->running = true;
    this->init();
}

MenuState::~MenuState() {
    // delete playButton;
    // delete helpButton;
    // delete settingsButton;
}

void MenuState::init() {
    setupTitle();
    setupButtons();
}

void MenuState::setupTitle() {
    sf::Font f;
    f.loadFromFile("fonts/PixeloidSans.ttf");
    this->font = f;
    sf::Text t("snake", font, 100);
    t.setFillColor(sf::Color(fontColor));
    t.setPosition(((gridSize.x * cellSize.x) - t.getGlobalBounds().width)/2, 200);
    this->text = t;
}

void MenuState::setupButtons() {
    int bWidth = 280;
    int bHeight = 80;
    int bStartingY = 500;
    Dimension size = Dimension(bWidth, bHeight);
    sf::Color color = sf::Color(0x47fc86ff);
    Coordinate c1 = Coordinate(((gridSize.x * cellSize.x) - bWidth)/2, bStartingY);
    Coordinate c2 = Coordinate(((gridSize.x * cellSize.x) - bWidth)/2, bStartingY + 100);
    Coordinate c3 = Coordinate(((gridSize.x * cellSize.x) - bWidth)/2, bStartingY + 200);
    this->playButton = new PlayButton(c1, size, color, gridSize, cellSize);
    this->settingsButton = new SettingsButton(c2, size, color);
    this->helpButton = new HelpButton(c3, size, color);
}

void MenuState::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (playButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) playButton->action();
            if (settingsButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) settingsButton->action();
            if (helpButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) helpButton->action();
        }
    }
}

void MenuState::tick() {
    tinkerTitleColor(fontColor);
    text.setFillColor(sf::Color(fontColor));
}

void MenuState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(text);
    playButton->render(window);
    settingsButton->render(window);
    helpButton->render(window);
    window.display();
}

uint8_t waveTinker(uint8_t x);

void MenuState::tinkerTitleColor(uint32_t& fontColor) {
    uint32_t r = ((fontAnimCycle >> 24) + 3);
    uint32_t g = ((fontAnimCycle >> 16) + 2);
    uint32_t b = ((fontAnimCycle >> 8) + 1);
    fontAnimCycle = (r << 24 & 0xFF000000) | (g << 16 & 0x00FF0000) | (b << 8 & 0x0000FF00) | (fontColor & 0x000000FF);
    fontColor = (waveTinker(r) << 24 & 0xFF000000) | (waveTinker(g) << 16 & 0x00FF0000) | (waveTinker(b) << 8 & 0x0000FF00) | (fontColor & 0x000000FF);
}

uint8_t waveTinker(uint8_t x) {
    return 255*abs(sin(2*M_PI*x/255));
}