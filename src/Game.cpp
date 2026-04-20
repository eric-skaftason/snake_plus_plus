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
void Game::update() {
    const std::vector<Coordinate> snake_positions = snake.getPositions();

    this->playing = this->snake.move();
    
}

// Public methods
void Game::run() {
    this->playing = true;

    using Clock = std::chrono::steady_clock;
    auto previousTime = Clock::now();

    while (this->renderer.getWindowIsOpen()) {
        auto currentTime = Clock::now();

        std::chrono::milliseconds deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - previousTime);
        previousTime = currentTime;
        long long ms = deltaTime.count();

        // Process events
        this->renderer.pollEvents();

        // Update
        this->update();

        // Render
        this->renderer.render(this->playing, this->snake, this->food);

        // Delay
        if (ms < this->updateDelay) {
            std::this_thread::sleep_for(std::chrono::milliseconds(this->updateDelay - ms));
        }
    }
}