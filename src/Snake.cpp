#include <vector>

#include "include/utils/Coordinate.h"
#include "include/Snake.h"


class Snake {
private:
    std::vector<Coordinate> positions;

    void removePosition(int index) {
        positions.erase(positions.begin() + index);
    }

public:

    void move() {

    }

    void grow() {

    }

    void setDirection() {

    }

    bool checkSelfCollision() {

    }

    // accessor methods
    const std::vector<Coordinate> &getPositions() const {
        return positions;
    }

    void reset() {

    }

};