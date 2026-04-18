#include <vector>

#include "utils/Coordinate.h"
#include "Food.h"

int Food::getIndexByCoords(int row, int col) {
    int index = -1;

    for (unsigned long i = 0; i < positions.size(); i++) {
        if (
            row == positions[i].row &&
            col == positions[i].col
        ) {
            index = i;
            break;
        }
    }

    return index;
}

void Food::removeFood(int row, int col) {
    int index = getIndexByCoords(row, col);

    if (index == -1) return;

    positions.erase(positions.begin() + index);
}

void Food::addFood(int row, int col) {
    positions.push_back(Coordinate(row, col));
}

const std::vector<Coordinate>& Food::getPositions() const {
    return positions;
}