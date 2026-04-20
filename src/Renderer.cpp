#include "Renderer.h"

// Can be included here (in the .cpp and not the .h) because Food and Snake are only ever references
#include "Food.h"
#include "Snake.h"

// Private methods
void Renderer::initWindow() {
    this->window = new sf::RenderWindow(this->videoMode, "Snake++", sf::Style::Default);

    this->window->setFramerateLimit(30);
}

void Renderer::renderTile(int row, int col, sf::Color color) {
    const int x = this->cell_width * col;
    const int y = this->cell_height * row;
    sf::RectangleShape tile(sf::Vector2f(this->cell_width, this->cell_height));

    tile.setPosition(x, y);
    tile.setFillColor(color);

    this->window->draw(tile);
}

// Constructor / Destructor
Renderer::Renderer(int rows, int cols) {
    this->videoMode.width = this->width;
    this->videoMode.height = this->height;

    this->cell_width = this->width / cols;
    this->cell_height = this->height / rows;

    this->rows = rows;
    this->cols = cols;

    initWindow();
}

Renderer::~Renderer() {
    delete this->window; // deallocate memory
}

// Accessors
const bool Renderer::getWindowIsOpen() const {
    return this->window->isOpen();

    // Equivalent to this:
    // *((*this).window).isOpen();
}

// Public methods
void Renderer::render(bool playing, const Snake& snake, const Food& food) {
    // Check game state
    if (!playing) {
        this->window->clear(sf::Color(64, 64, 64, 255));
        this->window->display();
        return;
    }

    // Clear old frame
    this->window->clear(sf::Color(0, 0, 0, 255));

    // Render new frame
    for (int r = 0; r < this->rows; r++) {
        for (int c = 0; c < this->cols; c++) {
            if (snake.isSnakeAt(r, c)) renderTile(r, c, this->snake_colour);
            else if (food.isFoodAt(r, c)) renderTile(r, c, this->food_colour);
            // otherwise don't render anything
        }
    }


    // Display frame
    this->window->display();
}

void Renderer::pollEvents() {
    while (this->window->pollEvent(this->event)) {
        switch (this->event.type) {
            case sf::Event::Closed:
                this->window->close();
                break;
            case sf::Event::KeyPressed:
                if (this->event.key.code == sf::Keyboard::Escape) this->window->close();
                break;
        }
    }
}
