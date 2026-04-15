#pragma once

#include "include/Food.h"
#include "include/Grid.h"
#include "include/Snake.h"
#include "include/Renderer.h"

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