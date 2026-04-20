#pragma once

class Snake {
private:
    std::vector<Coordinate> positions;

    // 0-up, 1-right, 2-down, 3-left
    int direction;
    int rows, cols;

    void eraseTail();

    const Coordinate& getHeadPosition() const;

    void insertNewHead(Coordinate head);

    void removePosition(int index);

public:
    Snake(int rows, int cols);

    bool willCollideWithSelf(Coordinate head);
    bool willBeOutOfBounds(Coordinate head);

    bool move();

    void grow();

    void setDirection();

    // accessor methods
    const std::vector<Coordinate> &getPositions() const;
    
    const bool isSnakeAt(int row, int col) const;

    void reset();

};