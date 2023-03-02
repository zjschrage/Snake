#pragma once
#include <queue>
#include <set>
#include "coordinate.h"
#include "dimension.h"
#include "cell.h"

class Grid {
public:
    Grid() = default;
    Grid(const Dimension& gridSize, const Dimension& cellSize);
    ~Grid() = default;
    int getLength() {return length;};
    int getWidth() {return width;};
    std::queue<Coordinate>& getUpdateQueue() {return updateQueue;};
    std::set<Coordinate>& getUpdateSet() {return updateSet;};
    bool inBounds(const Coordinate& c);
    Coordinate getWrappedCoordinate(const Coordinate& c);
    void setCell(const Coordinate& c, const CellState& s);
    Cell getCell(const Coordinate& c);
    Coordinate spawnFood();

private:
    std::vector<std::vector<Cell>> grid;
    std::queue<Coordinate> updateQueue;
    std::set<Coordinate> updateSet;
    int length;
    int width;
};