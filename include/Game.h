#pragma once

#include "Food.h"
#include "Grid.h"
#include "Snake.h"
#include "Renderer.h"

class Game {
private:
    int rows = 10;
    int cols = 10;
    
    Grid grid;
    Food food;
    Snake snake = Snake(rows, cols);

    int updateDelay = 500; // ms

    bool playing = false;

    Renderer renderer = Renderer(rows, cols);

    void update();

public:
    Game();

    void run();
};