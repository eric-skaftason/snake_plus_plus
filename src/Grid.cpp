#include "Grid.h"

Grid::Grid(int width, int height) {
    this->width = width;
    this->height = height;
}

bool Grid::isValidPosition(int row, int col) {
    if (row < 0 || row >= height || col < 0 || col >= width) return false;
    return true;
}