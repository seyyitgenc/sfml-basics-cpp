#include <SFML/System.hpp>
#include <iostream>
#include <chrono>
#include <thread>

void Move()
{
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "I'm Move Thread" << std::endl;
    }
}
void Animation()
{
    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "I'm Animation Thread" << std::endl;
    }
}
// threads runs at the same time
void Threads()
{
    // threads runs at the same time
    sf::Thread move(&Move);
    move.launch();
    sf::Thread Animation(&Animation);
    Animation.launch();

    for (int i = 0; i < 10; ++i)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        std::cout << "I'm the Main Thread" << std::endl;
    }
}