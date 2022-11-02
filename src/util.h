#pragma once
#include <string>
#include <vector>

namespace Util
{
    // int getRefreshRate();
    // int getDisplayRefreshRate(int i); delete
    // int getMonitorCount();
    void GetDesktopResolution(int &horizontal, int &vertical);
    std::string getExecutablePath();
    void setPointerCursor();
    void setDefaultCursor();
};