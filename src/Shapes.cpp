#include <SFML/Graphics.hpp>

void renderingThread(sf::RenderWindow *window)
{
    sf::Texture texture;
    if (!texture.loadFromFile("tree.png"))
    {
        // error
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
    window->setActive(true);
    while (window->isOpen())
    {
        window->clear();
        window->draw(circle);
        window->draw(sprite);
        window->display();
    }
}