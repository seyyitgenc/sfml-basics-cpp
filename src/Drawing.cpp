#include <SFML/Graphics.hpp>
#include <string>
#include "TileMap.h"

void renderingThread(sf::RenderWindow *window)
{
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };
    TileMap map;
    if (!map.load("tilemap-tileset.png", sf::Vector2u(32, 32), level, 16, 8))
    {
        // error
    }
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

    // line with thickness
    sf::RectangleShape line1(sf::Vector2f(150, 5));
    line1.rotate(45);
    sf::Vertex line2[] =
        {
            sf::Vertex(sf::Vector2f(50.f, 10.f)),
            sf::Vertex(sf::Vector2f(150.f, 150.f)),
            sf::Vertex(sf::Vector2f(160.f, 10.f)),
            sf::Vertex(sf::Vector2f(250.f, 150.f)),
        };

    // vertexArrays

    sf::VertexArray vertexTriangle(sf::Triangles, 3);
    vertexTriangle[0].position = sf::Vector2f(0, 0);
    vertexTriangle[1].position = sf::Vector2f(100, 100);
    vertexTriangle[2].position = sf::Vector2f(0, 100);

    vertexTriangle[0].color = sf::Color(255, 0, 0);
    vertexTriangle[1].color = sf::Color(0, 255, 0);
    vertexTriangle[2].color = sf::Color(0, 0, 255);

    // create a quad
    sf::VertexArray quad(sf::Quads, 4);

    // define it as a rectangle, located at (10, 10) and with size 100x100
    quad[0].position = sf::Vector2f(10.f, 10.f);
    quad[1].position = sf::Vector2f(42.f, 10.f);
    quad[2].position = sf::Vector2f(42.f, 42.f);
    quad[3].position = sf::Vector2f(10.f, 42.f);

    // define its texture area to be a 32x32 rectangle starting at (0, 0)
    quad[0].texCoords = sf::Vector2f(0.f, 0.f);
    quad[1].texCoords = sf::Vector2f(32.f, 0.f);
    quad[2].texCoords = sf::Vector2f(32.f, 32.f);
    quad[3].texCoords = sf::Vector2f(0.f, 32.f);
    window->setActive(true);
    while (window->isOpen())
    {
        window->clear();
        // window->draw(circle);
        // window->draw(sprite);
        // window->draw(triangle);
        // window->draw(square);
        // window->draw(octagon);
        // window->draw(rectangle);
        // window->draw(convex);
        // window->draw(line2, 4, sf::TriangleStrip);
        // window->draw(vertexTriangle);
        // window->draw(quad, &dirtTile);
        window->draw(map);
        window->display();
    }
}