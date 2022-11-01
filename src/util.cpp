#include <Windows.h>
#include <iostream>
#include "util.h"

int Util::getRefreshRate()
{
    DEVMODE screen;
    memset(&screen, 0, sizeof(DEVMODE));
    if (!EnumDisplaySettings(NULL, 0, &screen)) {
        return -1;
    }
    return screen.dmDisplayFrequency;
}

void Util::GetDesktopResolution(int& horizontal, int& vertical)
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