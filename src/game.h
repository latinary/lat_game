#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <atomic>

using Font = sf::Font;

class Game
{
private:
    sf::RenderWindow* window;
    static Game* inst_;
    float fps = 0.f;
    void pollEvents();
    void init();
    void run();
    void createThread();
    void onResize(int x, int y);
    void onWindowClosed();
public:
    static sf::Font mainFont;
    static sf::Font subFont;
    Game();
    ~Game();
    void update();
    void render();
    int getFramerate();
    sf::Window* getWindow();
    static Game* getInstance();
    std::string getName();
    void setTitle(std::string title);
    bool isFullscreen();
    void toggleFullscreen();
    void exit();
    Font getMainFont();
};