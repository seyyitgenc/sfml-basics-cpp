#include <SFML/Graphics.hpp>

void renderingThreadVerticies(sf::RenderWindow *window)
{
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
    quad[0].position = sf::Vector2f(110.f, 10.f);
    quad[1].position = sf::Vector2f(142.f, 10.f);
    quad[2].position = sf::Vector2f(142.f, 42.f);
    quad[3].position = sf::Vector2f(110.f, 42.f);

    // define its texture area to be a 32x32 rectangle starting at (0, 0)
    quad[0].texCoords = sf::Vector2f(0.f, 0.f);
    quad[1].texCoords = sf::Vector2f(32.f, 0.f);
    quad[2].texCoords = sf::Vector2f(32.f, 32.f);
    quad[3].texCoords = sf::Vector2f(0.f, 32.f);

    window->setActive(true);
    while (window->isOpen())
    {
        window->clear();
        window->draw(quad);
        window->draw(vertexTriangle);
        window->draw(line1);
        window->draw(line2, 4, sf::LineStrip);
        window->display();
    }
}