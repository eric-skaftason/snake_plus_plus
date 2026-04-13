class Grid {

private:
    int width;
    int height;

public:
    Grid(int width = 10, int hight = 10) {
        this->width = width;
        this->height = height;
    }

    bool isValidPosition(int row, int col) {
        if (row < 0 || row >= height || col < 0 || col >= width) return false;

        return true;
    }
};
