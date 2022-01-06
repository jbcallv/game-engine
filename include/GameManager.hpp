#pragma once
#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "GameState.hpp"
#include "Constants.hpp"

class GameState;

class GameManager {
public:
    GameManager(sf::RenderWindow& window);
    ~GameManager();

    void changeState(std::unique_ptr<GameState> state);
    void pushState(std::unique_ptr<GameState> state);
    void popState(std::unique_ptr<GameState> state);

    void gameLoop();

    void handleEvents();
    void Update();
    void Draw();

    bool running;
private:
    sf::RenderWindow& window;
    sf::Clock clock;
    sf::Time time;
    float dt = 0;
};

#endif