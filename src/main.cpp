#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

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

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Engine Test", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    sf::Time time;
    float dt = 0;

    Joe joe(sf::Vector2f(32, 40));
    SpriteSheet ss("../tests/images/adventurer-sheet.png", sf::Vector2i(50, 37));
    ss.setAnimation(1);
    ss.setPosition(sf::Vector2f(0, 25));

    Tilemap tm;
    tm.load("../tests/images/tileset1.png", room1, sf::Vector2u(8, 8), 8, 10);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        time = clock.restart();
        dt = time.asSeconds();

        window.clear();
        tm.Draw(window);
        //ss.Draw(window);
        //ss.Update(dt, 0.2f);
        joe.Draw(window);
        joe.Update(dt);

        window.display();
    }

    return 0;
}
