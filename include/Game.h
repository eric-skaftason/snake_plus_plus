#pragma once

#include "Food.h"
#include "Grid.h"
#include "Snake.h"
#include "Renderer.h"

class Game {
private:
    int rows = 20;
    int cols = 20;
    
    Grid grid;
    Food food;
    Snake snake = Snake(rows, cols);

    int updateDelay = 500; // ms

    bool playing = false;

    Renderer renderer = Renderer(rows, cols);

    void update(int direction);

public:
    Game();

    void run();
};