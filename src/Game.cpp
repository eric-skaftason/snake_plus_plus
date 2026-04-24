#include <iostream>
#include <chrono>
#include <thread>

#include "utils/Coordinate.h"

#include "Food.h"
#include "Grid.h"
#include "Snake.h"
#include "Renderer.h"

#include "Game.h"

// Constructor
Game::Game() {
    this->playing = true;
}

// Private methods
void Game::update(int direction) {
    // const std::vector<Coordinate> snake_positions = snake.getPositions();

    this->snake.setDirection(direction);

    this->playing = this->snake.move();
    
}

// Public methods
void Game::run() {
    this->playing = true;

    using Clock = std::chrono::steady_clock;
    auto nextTick = Clock::now();

    while (this->renderer.getWindowIsOpen()) {
        // Process events
        int direction = this->renderer.pollEvents();

        // Update
        this->update(direction);

        // Render
        this->renderer.render(this->playing, this->snake, this->food);


        // Delay
        nextTick += std::chrono::milliseconds(this->updateDelay);
        std::this_thread::sleep_until(nextTick);
    }
}