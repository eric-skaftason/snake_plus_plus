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

    Renderer renderer = Renderer(rows, cols);

public:
    Game();

    void run();
    
    void update();    
};