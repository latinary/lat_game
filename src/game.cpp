#define NOMINMAX // fucking windows

// SFML
#include <SFML/Graphics.hpp>

// Windows SDK
#include <Windows.h>

// Standard libraries
#include <thread>
#include <atomic>
#include <iostream>
#include <math.h>
#include <algorithm>

// Game libraries
#include "input/keyboard.h"
#include "input/mouse.h"
#include "game.h"
#include "util.h"

// Objects
#include "objects/blob.h"

#define MIN_WIDTH 800
#define MIN_HEIGHT 600

bool sceneInit = false;
bool screenInit = false;

using Font = sf::Font;
std::atomic<bool> exit_thread_flag{false};

Game *Game::inst_ = NULL;
sf::Vector2f pos = sf::Vector2f(0, 0);
Font Game::mainFont;

Game::Game()
{
    inst_ = this;
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), this->getName(), sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
    this->init();
}

Game::~Game()
{
    delete this->window;
    exit_thread_flag = true;

    std::cout << "Game destroyed" << std::endl;
}

void Game::onResize(int x, int y)
{
    // Get window size
    sf::Vector2f size = static_cast<sf::Vector2f>(this->window->getSize());

    // Resize the view
    sf::View newView = sf::View(sf::FloatRect(0.f, 0.f, size.x, size.y));
    this->window->setView(newView);

    // Limit the size
    this->window->setSize(sf::Vector2u(
        std::max(MIN_WIDTH, (int)this->window->getSize().x),
        std::max(MIN_HEIGHT, (int)this->window->getSize().y)));
}

void Game::onWindowClosed()
{
    this->window->close();
    this->~Game(); // Destroy the game
}

void Game::pollEvents()
{
    sf::Event event;
    while (this->window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
        {
            this->onWindowClosed();
            break;
        }

        case sf::Event::Resized:
        {
            this->onResize(event.size.width, event.size.height);
            break;
        }

        case sf::Event::KeyPressed:
        {
            KeyboardManager::onKeyPressed(event.key.code); // Update state

            if (event.key.code == sf::Keyboard::F11)
            {
                this->toggleFullscreen();
            }

            // std::cout << "Key pressed: " << KeyboardManager::getKeyName(event.key.code) << std::endl;
            break;
        }

        case sf::Event::KeyReleased:
        {
            KeyboardManager::onKeyReleased(event.key.code);
            break;
        }

        case sf::Event::MouseButtonPressed:
        {
            MouseManager::onMousePressed(event.mouseButton.button);
            break;
        }

        case sf::Event::MouseButtonReleased:
        {
            MouseManager::onMouseReleased(event.mouseButton.button);
            break;
        }

        case sf::Event::MouseMoved:
        {
            MouseManager::onMouseMove(event.mouseMove);
            break;
        }

        default:
            break;
        }
    }
}

void Game::toggleFullscreen()
{
    if (this->isFullscreen())
    {
        std::cout << "Switching to windowed mode" << std::endl;

        int w = 800;
        int h = 600;

        this->window->create(sf::VideoMode(w, h), this->getName(), sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
        this->onResize(w, h);
    }
    else
    {
        std::cout << "Switching to fullscreen mode" << std::endl;

        int w, h;
        Util::GetDesktopResolution(w, h);

        this->window->setSize(sf::Vector2u(w, h)); // yeah
        this->onResize(w, h);                      // Call resize event
        this->window->create(sf::VideoMode(w, h), this->getName(), sf::Style::Fullscreen);
    }
}

bool Game::isFullscreen()
{
    sf::Vector2u window_size = this->window->getSize();
    int w, h;

    int w_ = window_size.x;
    int h_ = window_size.y;

    Util::GetDesktopResolution(w, h);

    return w_ == w && h_ == h;
}

void Game::init()
{
    // Util::getRefreshRate()
    this->window->setFramerateLimit(144); // limit FPS to refresh rate
    // this->window->setVerticalSyncEnabled(true);

    std::string gamePath = Util::getExecutablePath();

    std::cout << "Game path is " << gamePath << std::endl;

    // Load fonts
    std::cout << "Loading fonts..." << std::endl;

    if (!Game::mainFont.loadFromFile(gamePath + "\\assets\\fonts\\ayar.ttf"))
    {
        std::cout << "Failed to load font" << std::endl;
    }

    std::cout << "Game initialized" << std::endl;

    this->createThread();
    this->run();
}

void Game::exit()
{
    this->window->close();
    this->onWindowClosed();
}

void tickThread()
{
    // 20 times per second
    Game *instance = Game::getInstance();
    sf::RenderWindow *window = (sf::RenderWindow *)instance->getWindow();
    while (!exit_thread_flag)
    {
        instance->update();
        std::cout << Util::getRefreshRate() << "\tFPS" << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    // std::terminate();
}

void Game::createThread()
{
    std::cout << "Starting test thread" << std::endl;
    std::thread thread(&tickThread);
    thread.detach();
}

Game *Game::getInstance()
{
    if (inst_ == nullptr)
    {
        throw new std::runtime_error("Game::getInstance() called but instance is null");
    }
    return inst_;
}

void Game::setTitle(std::string title)
{
    this->window->setTitle(title);
}

std::string Game::getName()
{
    return "Lat Game";
}

sf::Window *Game::getWindow()
{
    return this->window;
}

Font Game::getMainFont()
{
    return Game::mainFont;
}

void Game::run()
{
    // ----------------------------
    // Blob *Mislav = new Blob(); |
    // Mislav->x = 5;            |
    // delete Mislav;           |     ---> ak obrises peder si
    // -------------------------      ---> Neeeeeeeeeeeeeeeeeeeeeeee

    while (this->window->isOpen())
    {
        this->pollEvents(); // on/off

        // Update frame
        this->window->clear(); // ---> ? nez

        // Render frame
        this->render();
        this->window->display();
    }
}

void Game::render()
{
}

void Game::update()
{
}