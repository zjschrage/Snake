#include "state_game.h"
#include <iostream>

GameState::GameState(const Dimension& gridSize, const Dimension& cellSize, const Coordinate& snakeStart, WrapStyle wrapStyle) {
    this->g = Grid(gridSize, cellSize);
    this->s = Snake(snakeStart);
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
        if (event.type == sf::Event::KeyPressed) tentativeDirection = getDirection(event.key.code);
    }
}

void GameState::tick() {
    currentDirection = changeDirection(tentativeDirection, currentDirection);
    Coordinate next = s.nextLocation(currentDirection);
    if (!g.inBounds(next)) {
        if (wrapStyle == TOROIDAL) {
            next = g.getWrappedCoordinate(next);
            if (!g.inBounds(next)) return;
        } else {
            running = false;
            return;
        }
    }
    CellState nextState = g.getCell(next).getState();
    switch(nextState) {
        case EMPTY:
            s.moveHead(next);
            g.setCell(s.getSnake()[s.getSnake().size()-1], EMPTY);
            s.moveTail();
            break;
        case SNAKE_BODY:
        case SNAKE_HEAD:
            running = false;
            break;
        case FOOD:
            s.moveHead(next);
            g.getUpdateSet().erase(next);
            g.getUpdateSet().insert(g.spawnFood());
            break;
    }
    for (Coordinate c : s.getSnake()) {
        g.setCell(c, SNAKE_BODY);
        g.getUpdateQueue().push(c);
    }
    g.setCell(s.getSnake()[0], SNAKE_HEAD);
}

void GameState::render(sf::RenderWindow& window) {
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