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

    void getInput();

public:
    
    void start();

    void debug();    
    
};