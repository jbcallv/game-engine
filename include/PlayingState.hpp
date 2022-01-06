#pragma once
#ifndef PLAYING_STATE_HPP
#define PLAYING_STATE_HPP

#include "GameState.hpp"
#include "GameManager.hpp"
#include "Joe.hpp"
#include "Tilemap.hpp"
#include "Maps.hpp"

class PlayingState : public GameState {
public:
    PlayingState(GameManager& gameManager);

    ~PlayingState();

    void pause();

    void resume();

    void handleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(float dt);
    void Draw(sf::RenderWindow& window);
    
private:
    Joe joe;
    Tilemap tilemap;
};

#endif