#include <vector>

#include "utils/Coordinate.h"
#include "Snake.h"

Snake::Snake(int rows, int cols) {
    this->direction = 3;

    this->rows = rows;
    this->cols = cols;

    this->positions.push_back(Coordinate(2, 5));
    this->positions.push_back(Coordinate(2, 4));
    this->positions.push_back(Coordinate(2, 3));
    this->positions.push_back(Coordinate(2, 2));
}

const std::vector<Coordinate>& Snake::getPositions() const {
    return this->positions;
}

void Snake::eraseTail() {
    if (positions.size() == 0) return;
    removePosition(positions.size() - 1);
}

const Coordinate& Snake::getHeadPosition() const {
    return this->positions[0];
}

const bool Snake::isSnakeAt(int row, int col) const {
    for (int i = 0; i < this->positions.size(); i++) {
        Coordinate pos = this->positions[i];

        if (pos.row == row && pos.col == col) return true;
    }
    return false;
}

void Snake::insertNewHead(Coordinate head) {
    this->positions.insert(this->positions.begin(), head);
}

void Snake::removePosition(int index) {
    this->positions.erase(positions.begin() + index);
}


// Public methods

bool Snake::willCollideWithSelf(Coordinate head) {
    // start i at 1 so it skips the head
    for (int i = 1; i < this->positions.size(); i++) {
        Coordinate position = this->positions[i];
        if (head.row == position.row && head.col == position.col) return true;
    }
    return false;
}

bool Snake::willBeOutOfBounds(Coordinate head) {
    if (head.row < 0 || head.col < 0 || head.row >= this->rows || head.col >= this->cols) return true;
    return false;
}

void Snake::setDirection(int direction) {
    if (direction < 0) return;
    this->direction = direction;
}

bool Snake::move() {
    Coordinate head = getHeadPosition();

    int new_row = head.row;
    int new_col = head.col;

    switch (direction) {
        case 0: // up
            new_row -= 1;
            break;

        case 1: // down
            new_row += 1;
            break;

        case 2: // left
            new_col -= 1;
            break;

        case 3: // right
            new_col += 1;
            break;
    }

    Coordinate newHead(new_row, new_col);

    // Safety checks
    if (willCollideWithSelf(newHead) || willBeOutOfBounds(newHead)) return false;

    insertNewHead(newHead);
    eraseTail();
    
    return true;
}