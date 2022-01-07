#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Menu.hpp"
#include "Constants.hpp"
#include "Maps.hpp"
#include "SpriteSheet.hpp"
#include "SoundHandler.hpp"
#include "MusicHandler.hpp"
#include "ParticleSystem.hpp"
#include "TextSystem.hpp"
#include "TextBox.hpp"
#include "Tilemap.hpp"
#include "Button.hpp"
#include "Joe.hpp"
#include "Frank.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Engine Test", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    sf::Time time;
    float dt = 0;

    Joe joe(sf::Vector2f(32, 40));
    //SpriteSheet ss("../tests/images/adventurer-sheet.png", sf::Vector2i(50, 37));
    //ss.setAnimation(0);
    
    Frank frank(sf::Vector2f(32, 40));

    Tilemap tm;
    tm.load("../tests/images/tileset1.png", room1, sf::Vector2u(8, 8), 8, 10);
    bool MainMenu = true;
    
    Menu mm = Menu();
    
    sf::RectangleShape wall;
    wall.setFillColor(sf::Color::Red);
    wall.setSize(sf::Vector2f(10,10));
    wall.setPosition(50,50);
    
    std::cout << "hey" << std::flush;
    
    

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            MainMenu = mm.MenuWhile(window,event);
        }
            


        window.clear();
        time = clock.restart();
        dt = time.asSeconds();
        
        tm.Draw(window);
        //ss.Draw(window);
        //ss.Update(dt, 0.2f);
        if (joe.Update(dt)){
            std::cout << "Collision" << std::flush;
        }
        joe.Draw(window);
        frank.Update(dt);
        frank.Draw(window);
        window.draw(wall);
        
        window.display();
    }

    return 0;
}
