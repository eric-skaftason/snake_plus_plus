#pragma once

class Snake {
private:
    std::vector<Coordinate> positions;

    // 0-up, 1-right, 2-down, 3-left
    int direction;

    void eraseTail();

    const Coordinate& getHeadPosition() const;

    void setHead(Coordinate head);

    void removePosition(int index);

public:
    Snake();

    void move();

    void grow();

    void setDirection();

    bool checkSelfCollision();

    // accessor methods
    const std::vector<Coordinate> &getPositions() const;

    void reset();

};