#pragma once

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Renderer {
private:
    // set the renderwindow as a pointer to give control over when to delete it
    sf::RenderWindow* window;
    sf::Event event;

    sf::VideoMode videoMode;

    void initWindow();

public:
    Renderer(int windowWidth = 640, int windowHeight = 480);
    ~Renderer();

    void render();

};