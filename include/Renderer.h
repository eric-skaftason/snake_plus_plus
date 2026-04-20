#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Food;
class Snake;

class Renderer {
private:
    // set the renderwindow as a pointer to give control over when to delete it
    // helps for when aking a resizable window
    sf::RenderWindow* window;
    sf::Event event;

    sf::VideoMode videoMode;

    int width = 200;
    int height = 200;

    int cell_width, cell_height;
    int rows, cols;

    sf::Color food_colour = sf::Color::Red;
    sf::Color snake_colour = sf::Color::Blue;

    void initWindow();

    void renderTile(int row, int col, sf::Color color);

public:
    Renderer(int rows, int cols);
    ~Renderer();

    void render(const Snake& snake, const Food& food);
    void pollEvents();

    const bool getWindowIsOpen() const;

};