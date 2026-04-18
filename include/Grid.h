#pragma once

class Grid {
private:
    int width;
    int height;

public:
    Grid(int width = 10, int height = 10);

    bool isValidPosition(int row, int col);
};