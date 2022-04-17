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

    sf::Texture texture;
    if (!texture.loadFromFile("tree.png"))
    {
        std::cout << "Somethings Wrong" << std::endl;
    }
    sf::Sprite sprite;
    sprite.setTexture(texture);
    sprite.setTextureRect(sf::IntRect(0, 0, 48, 32));
    sprite.setScale(sf::Vector2f(4, 4)); // absolute scale factor
    // sprite.setOrigin(sf::Vector2f(25.f, 25.f));

    sf::CircleShape circle(60);
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition(100, 200);
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(100, 100, 100));
    circle.setTexture(&texture);
    circle.setTextureRect(sf::IntRect(0, 0, 100, 100));
    // circle.setPointCount(10000);

    // sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent

    sprite.setColor(sf::Color(0, 255, 0)); // green

    // screen.setVerticalSyncEnabled(true); //never use both of them at the same time
    screen.setFramerateLimit(60); // it's not much accurate like setVerticalSyncEnabled
    while (screen.isOpen())
    {
        sf::Event event;
        // event loop is MUST
        screen.setActive(false);
        sf::Thread thread(&renderingThread, &screen);
        thread.launch();
        while (screen.pollEvent(event))
        {
            // "close requested" event: we close the window
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