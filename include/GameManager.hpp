#pragma once
#ifndef GAME_MANAGER_HPP
#define GAME_MANAGER_HPP

#include <iostream>
#include <stack>
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
    void popState();

    void gameLoop();

    void handleEvents(sf::Event& event);
    void Update(float dt);
    void Draw();

    bool running = true;

private:
    sf::RenderWindow& window;
    sf::Clock clock;
    sf::Time time;
    float dt = 0;

    std::stack<std::unique_ptr<GameState>> states;
};

#endif