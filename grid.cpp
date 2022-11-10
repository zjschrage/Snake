#include <memory>
#include "grid.h"
#include "dimension.h"

Grid::Grid(const Dimension& gridSize, const Dimension& cellSize) {
    this->length = gridSize.x;
    this->width = gridSize.y;
    for (int i = 0; i < length; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < width; j++) {
            row.push_back(Cell(Coordinate(i, j), cellSize));
        }
        this->grid.push_back(row);
    }
}

bool Grid::inBounds(const Coordinate& c) {
    return c.x >= 0 && c.x < this->length && c.y >= 0 && c.y < this->width; 
}

Coordinate Grid::getWrappedCoordinate(const Coordinate& c) {
    int x = c.x;
    int y = c.y;
    if (c.x < 0) x = length - 1;
    else if (c.x >= length) x = 0;
    if (c.y < 0) y = width - 1;
    else if (c.y >= width) y = 0;
    return Coordinate(x, y);
}

void Grid::setCell(const Coordinate& c, const CellState& s) {
    grid[c.x][c.y].changeState(s);
}

Cell Grid::getCell(const Coordinate& c) {
    return grid[c.x][c.y];
}

Coordinate Grid::spawnFood() {
    std::vector<std::pair<Coordinate, Cell*>> empty;
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < width; j++) {
            if (grid[i][j].getState() == EMPTY) empty.push_back(std::make_pair(Coordinate(i, j), &grid[i][j]));
        }
    }
    int idx = ((float)rand()/(float)RAND_MAX) * empty.size();
    empty[idx].second->changeState(FOOD);
    return empty[idx].first;
}