#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class KeyboardManager
{
private:
    static bool keyTable[sf::Keyboard::KeyCount];
public:
    // ~KeyboardManager();
    static void onKeyPressed(sf::Keyboard::Key key);
    static void onKeyReleased(sf::Keyboard::Key key);
    static bool isKeyPressed(sf::Keyboard::Key key);
    static const char* getKeyName(sf::Keyboard::Key key);
};