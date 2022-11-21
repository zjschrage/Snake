#include "state_settings.h"
#include "constants.h"

SettingsState::SettingsState() {
    this->running = true;
    this->init();
}

SettingsState::~SettingsState() {
    //delete menuButton;
}

void SettingsState::init() {
    setupText();
    setupBackButton();
}

void SettingsState::setupText() {
    sf::Font f;
    f.loadFromFile("fonts/PixeloidSans.ttf");
    this->font = f;
    std::string text = "Settings Page\nToggle on Audio, Toroidal Mode (Wrap)\nOr change size of play area\n";
    sf::Text t(text, font, 50);
    t.setFillColor(sf::Color::Cyan);
    t.setPosition(50, 50);
    this->text = t;
}

void SettingsState::setupBackButton() {
    int bWidth = BUTTON_WIDTH;
    int bHeight = BUTTON_LENGTH;
    int bStartingY = 1000;
    Dimension size = Dimension(bWidth, bHeight);
    Dimension size2 = Dimension(bHeight, bHeight);
    sf::Color color = sf::Color(BUTTON_COLOR);
    Coordinate c = Coordinate((DIM_X - bWidth)/2, bStartingY);
    Coordinate c2 = Coordinate((DIM_X - bWidth)/2, bStartingY - 300);
    Coordinate c3 = Coordinate((DIM_X - bWidth)/2, bStartingY - 200);
    menuButton = new MenuButton(c, size, color);
    audioButton = new AudioButton(c2, size2, color);
    wrapButton = new WrapButton(c3, size2, color);
}

void SettingsState::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) menuButton->action();
            if (audioButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) audioButton->action();
            if (wrapButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) wrapButton->action();
        }
    }
}

void SettingsState::tick() {

}

void SettingsState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(text);
    menuButton->render(window);
    audioButton->render(window);
    wrapButton->render(window);
    window.display();
}