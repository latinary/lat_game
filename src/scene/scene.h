// "basically onak imas jednu scenu gdje se dogada main shit i onda imamo editor scene basically onak cijeli drugi page ak razumijes." - Damir, 19:49, 1.11.2022.
// "razumijem." - Leon, 19:50, 1.11.2022.
#pragma once // "basically preventa rekurziju, onak rekurzivno includeanje", - Damir, 19:54, 1.11.2022.

class Scene
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void destroy() = 0;
};