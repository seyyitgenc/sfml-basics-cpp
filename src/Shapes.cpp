#include <SFML/Graphics.hpp>

void renderingThreadShapes(sf::RenderWindow *window)
{
    sf::Texture tree;
    if (!tree.loadFromFile("tree.png"))
    {
        // error
    }
    sf::Texture dirtTile;
    if (!dirtTile.loadFromFile("tree.png"))
    {
        // error
    }
    sf::Sprite sprite;
    sprite.setTexture(tree);
    sprite.setTextureRect(sf::IntRect(0, 0, 100, 150));
    sprite.setScale(sf::Vector2f(4, 4)); // absolute scale factor
    // sprite.setOrigin(sf::Vector2f(25.f, 25.f));

    sf::CircleShape circle(60);
    circle.setFillColor(sf::Color(100, 250, 50));
    circle.setPosition(100, 200);
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color(100, 100, 100));
    circle.setTexture(&tree);
    circle.setTextureRect(sf::IntRect(0, 0, 100, 100));
    // sprite.setColor(sf::Color(255, 255, 255, 128)); // half transparent
    sprite.setColor(sf::Color(0, 255, 0)); // green

    sf::CircleShape triangle(80, 3);
    triangle.setPosition(60, 30);
    triangle.setFillColor(sf::Color(255, 0, 0));
    sf::CircleShape square(80, 4);
    square.setPosition(240, 30);
    square.setFillColor(sf::Color(255, 0, 0));
    sf::CircleShape octagon(80, 8);
    octagon.setPosition(420, 30);
    octagon.setFillColor(sf::Color(255, 0, 0));
    // 120x60 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120, 60));
    rectangle.setPosition(200, 400);
    // convex shapes
    sf::ConvexShape convex;
    convex.setPointCount(6);
    convex.setPoint(0, sf::Vector2f(0, 0));
    convex.setPoint(1, sf::Vector2f(150, 10));
    convex.setPoint(2, sf::Vector2f(120, 90));
    convex.setPoint(3, sf::Vector2f(30, 100));
    convex.setPoint(4, sf::Vector2f(0, 50));
    convex.setPosition(0, 400);

    window->setActive(true);
    while (window->isOpen())
    {
        window->clear();
        window->draw(circle);
        window->draw(sprite);
        window->draw(triangle);
        window->draw(square);
        window->draw(octagon);
        window->draw(rectangle);
        window->draw(convex);
        window->display();
    }
}