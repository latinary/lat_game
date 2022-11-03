#pragma once
#include <string>
#include <vector>
#include <SFML/Graphics.hpp>

namespace Util
{
    // int getRefreshRate();
    // int getDisplayRefreshRate(int i); delete
    // int getMonitorCount();
    void GetDesktopResolution(int &horizontal, int &vertical);
    std::string getExecutablePath();
    void setPointerCursor();
    void setDefaultCursor();
    
    namespace GUI
    {
        sf::ConvexShape roundRect(sf::Vector2f pos, sf::Vector2f dimens, float radius, sf::Color color);
    };
};