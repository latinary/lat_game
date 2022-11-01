// Lat Game

#pragma GCC optimize("O3")

#include <SFML/Graphics.hpp>
#include <iostream>

#include "util.h"
#include "game.h"

int main()
{
    std::cout << "Starting game" << std::endl;
    std::cout << "Refresh rate is " << Util::getRefreshRate() << "hz." << std::endl;
    Game game;

    // system("pause");

    std::cout << "Goodbye!" << std::endl;

    return 0;
}