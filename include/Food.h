#pragma once

#include <vector>
#include "utils/Coordinate.h"

class Food {
private:
    std::vector<Coordinate> positions;

    int getIndexByRowCol(int row, int col);

public:

    const bool isFoodAt(int row, int col) const;

    void removeFood(int row, int col);

    void addFood(int row, int col);

    // const at the end means the method won't mutate the obj
    const std::vector<Coordinate>& getPositions() const;

};