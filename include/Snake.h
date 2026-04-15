#pragma once

class Snake {
private:
    std::vector<Coordinate> positions;

    void removePosition(int index);

public:
    void move();

    void grow();

    void setDirection();

    bool checkSelfCollision();

    // accessor methods
    const std::vector<Coordinate> &getPositions() const;

    void reset();

};