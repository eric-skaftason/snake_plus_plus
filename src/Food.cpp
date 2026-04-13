#include <vector>

#include "include/utils/Coordinate.h"

class Food {
private:
    std::vector<Coordinate> positions;

    int getIndexByCoords(int row, int col) {
        int index = -1;

        for (short i = 0; i < positions.size(); i++) {
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

public:

    void removeFood(int row, int col) {
        int index = getIndexByCoords(row, col);

        if (index == -1) return;

        positions.erase(positions.begin() + index);
    }

    void addFood(int row, int col) {
        positions.push_back(Coordinate(row, col));
    }

    const std::vector<Coordinate>& getPositions() const {
        return positions;
    }

};