#include <SFML/Graphics.hpp>
#include <iostream>
#include "mouse.h"

bool MouseManager::mouseTable[sf::Mouse::ButtonCount];
int MouseManager::mouseX = 0;
int MouseManager::mouseY = 0;

void MouseManager::onMousePressed(sf::Mouse::Button button)
{
    mouseTable[button] = true;
}

void MouseManager::onMouseReleased(sf::Mouse::Button button)
{
    mouseTable[button] = false;
}

void MouseManager::onMouseMove(sf::Event::MouseMoveEvent event)
{
    mouseX = event.x;
    mouseY = event.y;
}

int MouseManager::getMouseX()
{
    return mouseX;
}

int MouseManager::getMouseY()
{
    return mouseY;
}

sf::Vector2i MouseManager::getMousePos()
{
    return sf::Vector2i(mouseX, mouseY);
}

bool MouseManager::isMousePressed(sf::Mouse::Button button)
{
    return mouseTable[button];
}