#include <iostream>

#include "include/Food.h"
#include "include/Grid.h"
#include "include/Snake.h"
#include "include/Renderer.h"

class Game {
private:
    Grid grid = Grid(10, 10);
    Food food = Food();
    Snake snake = Snake();

    void getInput() {

    }

public:
    
    void start() {

    }

    void debug() {
        std::cout << "Debug\n";
        
        
    }
};