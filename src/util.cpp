#include <Windows.h>
#include <iostream>
#include <vector>
#include "util.h"

#define vector std::vector
#define cout std::cout

BOOL CALLBACK MonitorEnumProc(HMONITOR hMonitor, HDC hdcMonitor, LPRECT lprcMonitor, LPARAM dwData)
{
    int *Count = (int *)dwData;
    (*Count)++;
    return TRUE;
}

int Util::getMonitorCount()
{
    int count = 0;
    if (EnumDisplayMonitors(NULL, NULL, MonitorEnumProc, (LPARAM)&count))
        return count;
    return -1; // signals an error
}

int Util::getDisplayRefreshRate(int i)
{
    DEVMODEA screen;
    memset(&screen, 0, sizeof(DEVMODEA));
    if (!EnumDisplaySettingsA(NULL, 0, &screen)) // TODO: fix, gets info on first monitor
    {                                            // TODO: delete ;_;
        return -1;
    }
    return screen.dmDisplayFrequency;
}

int Util::getRefreshRate()
{
    int mx = 0;
    for (int i = 0; i < Util::getMonitorCount(); ++i)
    {
        int temp = Util::getDisplayRefreshRate(i);
        mx = (mx > temp ? mx : temp);
    }
    return mx;
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