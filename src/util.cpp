#include <Windows.h>
#include <iostream>
#include <vector>
#include "util.h"
#include <SFML/Graphics.hpp>
#include <math.h>

#define vector std::vector
#define cout std::cout

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
    int *Count = (int *)dwData;
    (*Count)++;
    return TRUE;
}

void Util::GetDesktopResolution(int &horizontal, int &vertical)
{
    horizontal = ::GetSystemMetrics(SM_CXSCREEN);
    vertical = ::GetSystemMetrics(SM_CYSCREEN);
}

std::string Util::getExecutablePath()
{
    char buffer[MAX_PATH];
    GetModuleFileNameA(NULL, buffer, MAX_PATH);
    std::string::size_type pos = std::string(buffer).find_last_of("\\/");
    return std::string(buffer).substr(0, pos);
}

void Util::setPointerCursor()
{
    HCURSOR cursor = LoadCursor(NULL, IDC_ARROW);
    SetCursor(cursor);
}

void Util::setDefaultCursor()
{
    HCURSOR cursor = LoadCursor(NULL, IDC_ARROW);
    SetCursor(cursor);
}

sf::ConvexShape Util::GUI::roundRect(sf::Vector2f pos, sf::Vector2f dimens, float radius, sf::Color color)
{
    int POINTS = 50;
    float x = pos.x;
    float y = pos.x;
    float rectWidth = dimens.x;
    float rectHeight = dimens.y;
    sf::ConvexShape rrect;
    rrect.setOutlineThickness(0);
    rrect.setPointCount(POINTS * 4);
    rrect.setFillColor(color);

    int point = 0;

    float X=0,Y=0;
    for(int i=0; i<POINTS; i++)
    {
        X+=radius/POINTS;
        Y=std::sqrt(radius*radius-X*X);
        rrect.setPoint(point, sf::Vector2f(X+x+rectWidth-radius,y-Y+radius));
        point++;
    }
    Y=0;
    for(int i=0; i<POINTS; i++)
    {
        Y+=radius/POINTS;
        X=std::sqrt(radius*radius-Y*Y);
        rrect.setPoint(point, sf::Vector2f(x+rectWidth+X-radius,y+rectHeight-radius+Y));
        point++;
    }
    X=0;
    for(int i=0; i<POINTS; i++)
    {
        X+=radius/POINTS;
        Y=std::sqrt(radius*radius-X*X);
        rrect.setPoint(point, sf::Vector2f(x+radius-X,y+rectHeight-radius+Y));
        point++;
    }
    Y=0;
    for(int i=0; i<POINTS; i++)
    {
        Y+=radius/POINTS;
        X=std::sqrt(radius*radius-Y*Y);
        rrect.setPoint(point, sf::Vector2f(x-X+radius,y+radius-Y));
        point++;
    }
    return rrect;

}