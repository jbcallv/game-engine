#pragma once
#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include "GameState.hpp"
//#include "TextSystem.hpp"
//#include "Button.hpp"
#include "Gui.hpp"
#include "GameManager.hpp"
#include "PlayingState.hpp"

class MenuState : public GameState {
public:
    MenuState(GameManager& gameManager);

    ~MenuState();

    void pause();

    void resume();

    void handleEvents(sf::Event& event, sf::RenderWindow& window);
    void Update(float dt);
    void Draw(sf::RenderWindow& window);
    
private:
    Gui::Button menuButton;
    std::string menuText;
    
};

#endif
