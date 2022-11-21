#include "state_game.h"
#include "state_menu.h"
#include "singleton.h"
#include "istate.h"
#include "score_manager.h"
#include "game_variables.h"
#include "audio.h"
#include <iostream>

GameState::GameState(const Dimension& gridSize, const Dimension& cellSize, const Coordinate& snakeStart, WrapStyle wrapStyle) {
    this->g = Grid(gridSize, cellSize);
    this->s = Snake(snakeStart);
    this->gridSize = gridSize;
    this->cellSize = cellSize;
    this->tentativeDirection = UP;
    this->currentDirection = UP;
    this->wrapStyle = wrapStyle;
    this->running = true;
    this->init();
}

void GameState::init() {
    initDirectionMap();
    g.getUpdateSet().insert(g.spawnFood());
}

void GameState::handleEvents(sf::RenderWindow& window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) window.close();
        if (running) {
            if (event.type == sf::Event::KeyPressed) tentativeDirection = getDirection(event.key.code);
        } 
        else {
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Key::Enter) reset();
            }
            if (event.type == sf::Event::MouseButtonPressed) reset();
        }
    }
}

void GameState::reset() {
    auto state = std::make_unique<MenuState>();
    Singleton<IState>::set(std::move(state));
}

void GameState::stop() {
    Singleton<ScoreManager>::get().addScore(s.getSnake().size());
    if (Singleton<GameVariables>::get().audio) Singleton<Audio>::get().die.play();
    running = false;
}

void GameState::tick() {
    if (!running) return;
    currentDirection = changeDirection(tentativeDirection, currentDirection);
    Coordinate next = s.nextLocation(currentDirection);
    if (!checkNextLocation(next)) return;
    CellState nextState = g.getCell(next).getState();
    setNextStates(next, nextState);
    updateCells();
}

bool GameState::checkNextLocation(Coordinate& next) {
    if (!g.inBounds(next)) {
        if (wrapStyle == TOROIDAL) {
            next = g.getWrappedCoordinate(next);
            if (!g.inBounds(next)) stop();
        } else stop();
    }
    return running;
}

void GameState::setNextStates(const Coordinate& next, const CellState& nextState) {
    switch(nextState) {
        case EMPTY:
            s.moveHead(next);
            g.setCell(s.getSnake()[s.getSnake().size()-1], EMPTY);
            s.moveTail();
            break;
        case SNAKE_BODY:
        case SNAKE_HEAD:
            stop();
            break;
        case FOOD:
            s.moveHead(next);
            g.getUpdateSet().erase(next);
            g.getUpdateSet().insert(g.spawnFood());
            if (Singleton<GameVariables>::get().audio) Singleton<Audio>::get().eat.play();
            break;
    }
}

void GameState::updateCells() {
    for (Coordinate c : s.getSnake()) {
        g.setCell(c, SNAKE_BODY);
        g.getUpdateQueue().push(c);
    }
    g.setCell(s.getSnake()[0], SNAKE_HEAD);
}

void GameState::render(sf::RenderWindow& window) {
    if (!running) return;
    window.clear();
    for (Coordinate c : g.getUpdateSet()) {
        window.draw(g.getCell(c).getGraphicCell());
    }
    std::queue<Coordinate>& updateQueue = g.getUpdateQueue();
    while (!updateQueue.empty()) {
        Coordinate c = updateQueue.front();
        window.draw(g.getCell(c).getGraphicCell());
        updateQueue.pop();
    }
    window.display();
}