#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>

class ParticleSystem : public sf::Drawable, public sf::Transformable
{
public:
    ParticleSystem(unsigned int count) : m_particles(count),
                                         m_vertices(sf::Points, count),
                                         m_lifetime(sf::seconds(3.f)),
                                         m_emitter(0.f, 0.f)
    {
    }

    void setEmitter(sf::Vector2f position)
    {
        m_emitter = position;
    }
    void update(sf::Time elapsed)
    {
        for (std::size_t i = 0; i < m_particles.size(); ++i)
        {
            Particle &p = m_particles[i];
            p.lifetime -= elapsed;

            if (p.lifetime <= sf::Time::Zero)
                resetParticle(i);
            m_vertices[i].position += p.velocity * elapsed.asSeconds();

            float ratio = p.lifetime.asSeconds() / m_lifetime.asSeconds();
            m_vertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);
        }
    }

private:
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const
    {
        // apply theu transform
        states.transform *= getTransform();

        // our particles don't use a texture
        states.texture = NULL;

        // draw the vertex array
        target.draw(m_vertices, states);
    }

private:
    struct Particle
    {
        sf::Vector2f velocity;
        sf::Time lifetime;
    };
    void resetParticle(std::size_t index)
    {
        float angle = (std::rand() % 360) * 3.14f / 180;
        float speed = (std::rand() % 50) + 50.f;

        m_particles[index].velocity = sf::Vector2f(std::cos(angle) * speed, std::sin(angle) * speed);
        m_particles[index].lifetime = sf::milliseconds((std::rand() % 2000) + 1000);
        m_vertices[index].position = m_emitter;
    }

    std::vector<Particle> m_particles;
    sf::VertexArray m_vertices;
    sf::Time m_lifetime;
    sf::Vector2f m_emitter;
};
void Particles()
{
    sf::RenderWindow screen(sf::VideoMode(512, 256), "Particles");
    screen.setPosition(sf::Vector2i(10, 10)); // re-position
    sf::Clock clock;
    ParticleSystem particles(1000);
    screen.setFramerateLimit(60);
    while (screen.isOpen())
    {
        sf::Event event;
        while (screen.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                screen.close();
        }
        sf::Vector2i mouse = sf::Mouse::getPosition(screen);
        particles.setEmitter(screen.mapPixelToCoords(mouse));
        sf::Time elapsed = clock.restart();
        particles.update(elapsed);

        screen.clear();
        screen.draw(particles);
        screen.display();
    }
}