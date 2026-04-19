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
    Renderer renderer = Renderer(640, 480);

public:
    Game();

    void run();
    
    void update();    
};