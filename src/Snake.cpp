#include <vector>

#include "utils/Coordinate.h"
#include "Snake.h"


const std::vector<Coordinate>& Snake::getPositions() const {
    return this->positions;
}

void Snake::removePosition(int index) {
    this->positions.erase(positions.begin() + index);
}