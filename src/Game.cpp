#include <iostream>
#include <chrono>
#include <thread>

#include <random>

#include "utils/Coordinate.h"

#include "Food.h"
#include "Snake.h"
#include "Renderer.h"

#include "Game.h"

// Constructor
Game::Game() {
    this->playing = true;

    while (this->food.isFoodShortage()) {
        generateFood();
    }
}

// Private methods
void Game::update(int direction) {
    // Get snake tail pos
    const Coordinate tailPos = this->snake.getTailPosition();

    // Move snake
    this->snake.setDirection(direction);
    this->playing = this->snake.move();

    const Coordinate headPos = this->snake.getHeadPosition();

    if (this->food.isFoodAt(headPos.row, headPos.col)) {
        this->food.removeFood(headPos.row, headPos.col);

        this->snake.grow(tailPos.row, tailPos.col);
    }



    // Generate food
    if (this->food.isFoodShortage()) {
        generateFood();
    }
}

void Game::generateFood() {
    std::random_device rd; 
    std::mt19937 gen(rd()); 
    std::uniform_int_distribution<> distr(0, this->rows * this->cols - 1);

    const int randNum = distr(gen);
    int row = randNum / this->cols;
    int col = randNum % this->cols;

    if (snake.isSnakeAt(row, col)) {
        generateFood();
    } else {
        food.addFood(row, col);
    }
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