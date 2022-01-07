#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <vector>

#include "GameManager.hpp"
#include "GameState.hpp"
#include "MenuState.hpp"
#include "Constants.hpp"
#include "MusicHandler.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Engine Test", sf::Style::Titlebar | sf::Style::Close);
    GameManager game(window);
    
    game.pushState(std::unique_ptr<GameState>(new MenuState(game)));
    game.gameLoop();

    return 0;
}
