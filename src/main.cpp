// Lat Game
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,fma,abm,mmx,avx,avx2,tune=native")

#include <SFML/Graphics.hpp>
#include <iostream>

#include "util.h"
#include "game.h"

int main()
{
    std::cout << "Starting game" << std::endl;
    // std::cout << "Refresh rate is " << Util::getRefreshRate() << "hz." << std::endl; --> funkcija ne postoji vise tak da je red vjv beskoristan
    Game game;
    std::cout << "Goodbye!" << std::endl;

    return 0;
}