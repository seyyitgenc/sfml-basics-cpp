#include <SFML/Graphics.hpp>
#include <iostream>

void renderingThread(sf::RenderWindow *);

void Window()
{
    // sf::Window window(sf::VideoMode(700,700),"title"); //alternative window drawing
    sf::RenderWindow screen(sf::VideoMode(600, 600), "");
    screen.setPosition(sf::Vector2i(10, 10)); // re-position
    // screen.setSize(sf::Vector2u(600, 600));   // re-size
    screen.setTitle("SFML Window"); // re-title
    screen.setActive(false);
    sf::Thread thread(&renderingThread, &screen);
    thread.launch();
    // screen.setVerticalSyncEnabled(true); //never use both of them at the same time
    screen.setFramerateLimit(60); // it's not much accurate like setVerticalSyncEnabled
    while (screen.isOpen())
    {
        sf::Event event;
        // event loop is MUST
        while (screen.pollEvent(event))
        {
            // can be used with switch - case
            if (event.type == sf::Event::Closed)
                // window close event
                screen.close();
            if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
            {
                std::cout << "workingg" << std::endl;
            }
            if (event.type == sf::Event::Resized)
            {
                std::cout << event.size.width << std::endl;
                std::cout << event.size.height << std::endl;
            }
        }
    }
}