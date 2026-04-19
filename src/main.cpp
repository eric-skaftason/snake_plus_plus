#include "Game.h"

int main() {
    Game game = Game();


    return 0;
}

// #include <SFML/System.hpp>
// #include <SFML/Graphics.hpp>
// #include <SFML/Window.hpp>

// int main() {
    
//     sf::RenderWindow window(sf::VideoMode(640, 480), "Name", sf::Style::Default);
//     sf::Event event;

//     // Game loop
//     while (window.isOpen()) {
//         // Event polling
//         while (window.pollEvent(event)) {
//             switch (event.type) {
//                 case sf::Event::Closed:
//                     window.close();
//                     break;
//                 case sf::Event::KeyPressed:
//                     if (event.key.code == sf::Keyboard::Escape) window.close();
//                     break;
//             }
//         }
//     }

//     // Update


//     // Render
//     window.clear(sf::Color::Blue);
//     window.display();


//     return 0;
// }