#include "state_help.h"
#include "constants.h"

HelpState::HelpState() {
    this->running = true;
    this->init();
}

HelpState::~HelpState() {
    //delete menuButton;
}

void HelpState::init() {
    setupText();
    setupBackButton();
}

void HelpState::setupText() {
    sf::Font f;
    f.loadFromFile("fonts/PixeloidSans.ttf");
    this->font = f;
    std::string text = "Welcome to Snake, use WASD to move.\nCollect as many green apples as possible\nAs you eat you will get longer\nDont crash into your self\n(or walls if not on toroidal mode)\nIf you crash, hit enter to return to menu\n\n\n\nGame by Zack Schrage";
    sf::Text t(text, font, 50);
    t.setFillColor(sf::Color::Cyan);
    t.setPosition(50, 50);
    this->text = t;
}

void HelpState::setupBackButton() {
    int bWidth = 280;
    int bHeight = 80;
    int bStartingY = 1000;
    Dimension size = Dimension(bWidth, bHeight);
    sf::Color color = sf::Color(0x47fc86ff);
    Coordinate c = Coordinate((DIM_X - bWidth)/2, bStartingY);
    menuButton = new MenuButton(c, size, color);
}

void HelpState::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (event.type == sf::Event::MouseButtonPressed) {
            if (menuButton->contains(Coordinate(event.mouseButton.x, event.mouseButton.y))) menuButton->action();
        }
    }
}

void HelpState::tick() {

}

void HelpState::render(sf::RenderWindow& window) {
    window.clear();
    window.draw(text);
    menuButton->render(window);
    window.display();
}