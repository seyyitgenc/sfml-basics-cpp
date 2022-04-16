#include <SFML/System.hpp>
#include <iostream>

// protect a piece of code by allowing only certain threads to access it while blocking the others.
sf::Mutex mutex;

void Move()
{
    sf::Lock lock(mutex);
    // if this for loop throws exception mutex will be unlocked
    for (int i = 0; i < 10; ++i)
    {
        sf::sleep(sf::milliseconds(100));
        std::cout << "I'm Move Thread" << std::endl;
    }
}
// non-member thread with one argument
void testtt(int &x)
{
    for (int i = 0; i < 10; ++i)
    {
        sf::sleep(sf::milliseconds(100));
        x += 5;
        std::cout << "I'm Animation Thread " << x << std::endl;
    }
}

// member thread
class MyClass
{
public:
    void func()
    {
        for (int i = 0; i < 10; i++)
        {
            sf::sleep(sf::milliseconds(100));
            std::cout << "I'm Member Thread" << std::endl;
        }
    }
};
// threads runs at the same time
void Threads()
{
    int y = 0;
    // threads runs at the same time
    sf::Thread move(&Move);
    sf::Thread run_animation(&testtt, y);
    MyClass object;
    sf::Thread thread(&MyClass::func, &object);

    move.launch();
    run_animation.launch();
    thread.launch();

    for (int i = 0; i < 10; ++i)
    {
        sf::sleep(sf::milliseconds(100));
        std::cout << "I'm the Main Thread" << std::endl;
    }
}