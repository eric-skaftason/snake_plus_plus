#pragma once

class Snake {
private:
    std::vector<Coordinate> positions;

    // 0-up, 1-down, 2-left, 3-right
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

    void setDirection(int direction);

    // accessor methods
    const std::vector<Coordinate> &getPositions() const;
    
    const bool isSnakeAt(int row, int col) const;

    void reset();

};