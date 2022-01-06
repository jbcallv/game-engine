#pragma once
#ifndef GAME_STATE_HPP
#define GAME_STATE_HPP

#include <SFML/Graphics.hpp>
#include "GameManager.hpp"

class GameManager;

class GameState {
public:
    /*
    * init and cleanup
    */
    GameState(GameManager&  gameManager);
    virtual ~GameState();

    /*
    * allows a state to temporarily be paused while
    * another one is started
    */
    virtual void pause()=0;
    virtual void resume()=0;


    virtual void handleEvents(sf::Event event)=0;
    virtual void Update(float dt)=0;
    virtual void Draw(sf::RenderWindow& window)=0;

private:
    GameManager& gameManager;
};

#endif