#include "Renderer.h"

// Can be included here (in the .cpp and not the .h) because Food and Snake are only ever references
#include "Food.h"
#include "Snake.h"

// Private methods
void Renderer::initWindow() {
    this->window.create(this->videoMode, "Snake++", sf::Style::Default);

    this->window.setFramerateLimit(30);
}

void Renderer::renderTile(int row, int col, sf::Color color) {
    const int x = this->cell_width * col;
    const int y = this->cell_height * row;
    sf::RectangleShape tile(sf::Vector2f(this->cell_width, this->cell_height));

    tile.setPosition(sf::Vector2f(x, y));
    tile.setFillColor(color);

    this->window.draw(tile);
}

// Constructor

// use C++ initializer list
/*
    When an obj is created
    1. Memory is allocated
    2. Members are created
    3. If an initlializer list exists use those values as a param
    ex. for the member videoMode, use the params: 500, 500

*/
Renderer::Renderer(int rows, int cols) :
    videoMode(sf::Vector2u(500, 500)),
    window(videoMode, "Snake++", sf::Style::Default)
{
    this->cell_width = videoMode.size.x / cols;
    this->cell_height = videoMode.size.y / rows;

    this->rows = rows;
    this->cols = cols;

    initWindow();
}


// Accessors
const bool Renderer::getWindowIsOpen() const {
    return this->window.isOpen();

    // Equivalent to this:
    // *((*this).window).isOpen();
}

// Public methods
void Renderer::render(bool playing, const Snake& snake, const Food& food) {
    // Check game state
    if (!playing) {
        this->window.clear(sf::Color(64, 64, 64, 255));
        this->window.display();
        return;
    }

    // Clear old frame
    this->window.clear(sf::Color(0, 0, 0, 255));

    // Render new frame
    for (int r = 0; r < this->rows; r++) {
        for (int c = 0; c < this->cols; c++) {
            if (snake.isSnakeAt(r, c)) renderTile(r, c, this->snake_colour);
            else if (food.isFoodAt(r, c)) renderTile(r, c, this->food_colour);
            // otherwise don't render anything
        }
    }


    // Display frame
    this->window.display();
}

int Renderer::pollEvents() {
    int result = -1; // default: no input

    /*
    SFML 2.x -> 3 port:
        
    Old code:
        sf::Event event;
        while (window.pollEvent(event)) {}

    - pollEvent took an sf::Event as an arg and set its value by reference
    - it then returned a true or false value depending on if there are any events left in the queue

    New code:
    - returns std::optional<sf::Event> meaning it returns a value or std::nullopt
    - if something returns, event is set, else it is std::nullopt
    - event is now a std::optional, a wrapper for the actual sf::Event obj
    - it is not a pointer but the value inside the wrapper can be accessed with the same API as a pointer, e.g. event->key
    */

    while (std::optional<sf::Event> event = window.pollEvent()) {

        if (event->is<sf::Event::Closed>()) {
            window.close();
        }

        // get if event matches
        if (auto key = event->getIf<sf::Event::KeyPressed>()) {

            if (key->code == sf::Keyboard::Key::Escape) {
                window.close();
            }

            switch (key->code) {
            case sf::Keyboard::Key::Up: result = 0; break;
            case sf::Keyboard::Key::Down: result = 1; break;
            case sf::Keyboard::Key::Left: result = 2; break;
            case sf::Keyboard::Key::Right: result = 3; break;
            default: break;
            }
        }
    }

    return result;
}
