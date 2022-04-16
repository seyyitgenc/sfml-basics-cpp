#include <iostream>
#include <SFML/Graphics.hpp>

void TimeModule()
{
    sf::Clock clock;
    sf::Time time1 = sf::milliseconds(100);
    sf::Time time2 = sf::microseconds(10000);
    sf::Int64 usec = time1.asMicroseconds();
    sf::Int32 msec = time1.asMilliseconds();

    float sec = time1.asSeconds();
    std::cout << "100 milisecond is  \n"
              << usec << " macrosecond\n"
              << msec << " miliseconds\n"
              << sec << "second" << std::endl;

    sf::Time sumtime = time1 + time2; // time can be operated
    sf::Time negtime = -time1;
    std::cout
        << "sum of time1 and time2 "
        << sumtime.asMilliseconds() << "\nnegative time" << negtime.asMilliseconds() << std::endl;

    sf::Time elapsedtime1 = clock.restart(); // clock.restart also return elapsed time
    std::cout << "first elapsed time " << elapsedtime1.asSeconds() << std::endl;
    // res timer
    std::cin.get();
    sf::Time elapsedtime2 = clock.getElapsedTime();
    std::cout << "second elapsed time " << elapsedtime2.asSeconds() << std::endl;
    std::cin.get();
}