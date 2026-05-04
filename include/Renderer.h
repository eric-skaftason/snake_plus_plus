#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Food;
class Snake;

class Renderer {
private:
    sf::VideoMode videoMode;
    sf::RenderWindow window;

    int cell_width, cell_height;
    int rows, cols;

    sf::Color food_colour = sf::Color::Red;
    sf::Color snake_colour = sf::Color::Blue;

    void initWindow();

    void renderTile(int row, int col, sf::Color color);

public:
    Renderer(int rows, int cols);

    void render(bool playing, const Snake& snake, const Food& food);
    int pollEvents();

    const bool getWindowIsOpen() const;

};