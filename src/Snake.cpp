#include <vector>

#include "include/utils/Coordinate.h"

#include "include/Snake.h"


class Snake {
private:
    std::vector<Coordinate> positions;

public:
    Snake();

    void move();

    void grow();

    void setDirection();

    bool checkSelfCollision();

    // accessor methods
    std::vector<Coordinate> getPositions() {

    }

    void reset();

};