#include <Windows.h>
#include <iostream>
#include <vector>
#include "util.h"
#include <SFML/Graphics.hpp>

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

void Util::GUI::roundRect(sf::Vector2f pos, sf::Vector2f dimens)
{

}