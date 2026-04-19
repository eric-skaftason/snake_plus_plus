#include "Renderer.h"

// Private methods
void Renderer::initWindow() {
    this->window = new sf::RenderWindow(this->videoMode, "Snake++", sf::Style::Default);
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

// Public methods
void Renderer::render() {

}