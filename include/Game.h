#pragma once

#include "Food.h"
#include "Grid.h"
#include "Snake.h"
#include "Renderer.h"

class Game {
private:
    Grid grid;
    Food food;
    Snake snake;

    int rows = 10;
    int cols = 10;

    int updateDelay = 500; // ms

    Renderer renderer = Renderer(rows, cols);

public:
    Game();

    void run();
    
    void update();    
};