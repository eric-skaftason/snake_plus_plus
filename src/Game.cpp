#include <iostream>

#include "Food.h"
#include "Grid.h"
#include "Snake.h"
#include "Renderer.h"

#include "Game.h"

// Constructor
Game::Game() {
    
}


// Public methods
void Game::run() {
    while (this->renderer.getWindowIsOpen()) {
        // Process events
        this->renderer.pollEvents();

        // Update
        this->update();

        // Render
        this->renderer.render();
    }
}

void Game::update() {

}

void Game::render() {
    
}