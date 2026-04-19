#include <vector>

#include "utils/Coordinate.h"
#include "Snake.h"

Snake::Snake() {
    this->direction = 1;

    this->positions.push_back(Coordinate(2, 2));
    this->positions.push_back(Coordinate(2, 3));
    this->positions.push_back(Coordinate(2, 4));
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

void Snake::setHead(Coordinate head) {
    this->positions.insert(this->positions.begin(), head);
}

void Snake::removePosition(int index) {
    this->positions.erase(positions.begin() + index);
}


// Public methods
void Snake::move() {
    eraseTail();

    Coordinate head = getHeadPosition();

    int new_row = -1, new_col = -1;

    switch (direction) {
        case 0:
            /* code */
            break;
        
        case 1:
            new_row = head.row;
            new_col = head.col + 1;
            break;
        case 2:
            break;
        case 3:
            break;
    }

    // Check if new head in in bounds


    // Set head
    setHead(Coordinate(new_row, new_col));

}