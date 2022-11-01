#pragma once
#include "../screen.h"

class MainMenu : public Screen
{
public:
    void render();
    void update();
    void init();
    void destroy();
};