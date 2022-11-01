#pragma once

#include <SFML/Graphics.hpp>

class MouseManager
{
private:
    static bool mouseTable[sf::Mouse::ButtonCount];
    static int mouseX;
    static int mouseY;
public:
    // ~Mouse();
    static void onMousePressed(sf::Mouse::Button button);
    static void onMouseReleased(sf::Mouse::Button button);
    static void onMouseMove(sf::Event::MouseMoveEvent event);
    static int getMouseX();
    static int getMouseY();
    static sf::Vector2i getMousePos();
    static bool isMousePressed(sf::Mouse::Button button);
};