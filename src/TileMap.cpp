#include <SFML/Graphics.hpp>
class TileMap : public sf::Drawable, public sf::Transformable
{
public:
    bool load(const std::string &tileset, sf::Vector2u tilesize, const int *tiles, unsigned int width, unsigned int height)
    {
        if (!m_tileset.loadFromFile(tileset))
            return false;
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        for (unsigned int i = 0; i < width; ++i)
        {
            for (unsigned int j = 0; j < height; ++j)
            {
                int tilenumber = tiles[i + j * width];

                int tu = tilenumber % (m_tileset.getSize().x / tilesize.x);
                int tv = tilenumber / (m_tileset.getSize().x / tilesize.x);

                sf::Vertex *quad = &m_vertices[(i + j * width) * 4];

                quad[0].position = sf::Vector2f(i * tilesize.x, j * tilesize.y);
                quad[1].position = sf::Vector2f((i + 1) * tilesize.x, j * tilesize.y);
                quad[2].position = sf::Vector2f((i + 1) * tilesize.x, (j + 1) * tilesize.y);
                quad[3].position = sf::Vector2f(i * tilesize.x, (j + 1) * tilesize.y);

                quad[0].texCoords = sf::Vector2f(tu * tilesize.x, tv * tilesize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tilesize.x, tv * tilesize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tilesize.x, (tv + 1) * tilesize.y);
                quad[3].texCoords = sf::Vector2f(tu * tilesize.x, (tv + 1) * tilesize.y);
            }
        }
        return true;
    }

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        states.transform *= getTransform();
        states.texture = &m_tileset;
        target.draw(m_vertices, states);
    }
    sf::VertexArray m_vertices;
    sf::Texture m_tileset;
};
const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1};
void renderingThreadTileMap(sf::RenderWindow *window)
{
    TileMap map;
    if (!map.load("tilemap-tileset.png", sf::Vector2u(32, 32), level, 16, 8))
    {
        // error
    }
    while (window->isOpen())
    {
        window->clear();
        window->draw(map);
        window->display();
    }
}