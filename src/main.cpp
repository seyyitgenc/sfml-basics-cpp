#include <SFML/Graphics.hpp>
#include <iostream>

void TimeModule();
void Threads();
int main()
{
    TimeModule();
    // the main thread continues to run...
    Threads();
    return 0;
}