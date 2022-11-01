#pragma once

class Screen
{
public:
    virtual void render() = 0;
    virtual void update() = 0;
    virtual void init() = 0;
    virtual void destroy() = 0;
};