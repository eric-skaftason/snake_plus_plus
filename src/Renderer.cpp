#include "Renderer.h"

// Private methods
void Renderer::initWindow() {
    this->window = new sf::RenderWindow(this->videoMode, "Snake++", sf::Style::Default);

    this->window->setFramerateLimit(30);
}

// Constructor / Destructor
Renderer::Renderer(int width, int height) {
    this->videoMode.width = width;
    this->videoMode.height = height;


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
void Renderer::render() {
    /*
        - clear old frame
        - render objects
        - display frame in window
    */

    // Clear old frame
    this->window->clear(sf::Color(0, 0, 0, 255));

    // Render new frame



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
