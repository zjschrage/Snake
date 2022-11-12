#pragma once

struct Coordinate {
    int x;
    int y;

    Coordinate() {}
    Coordinate(int x, int y) : x(x), y(y) {}
    Coordinate(const Coordinate& other) = default;

    bool operator<(const Coordinate& lhs) const {
        if (lhs.x == x) return (lhs.y < x);
        return (lhs.x < x);
    }
};