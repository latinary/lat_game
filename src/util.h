#pragma once
#include <string>
#include <vector>

namespace Util
{
    int getRefreshRate();
    void GetDesktopResolution(int& horizontal, int& vertical);
    std::string getExecutablePath();
    void setPointerCursor();
    void setDefaultCursor();
};