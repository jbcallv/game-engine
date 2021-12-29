#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Constants.hpp"
#include "SpriteSheet.hpp"
#include "SoundHandler.hpp"
#include "MusicHandler.hpp"
#include "ParticleSystem.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Engine Test", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    sf::Time time;
    float dt = 0;

    // for testing purposes only
    //sf::Vector2i spriteSize(50, 37);
    //SpriteSheet ss("C:/Projects/Adventurer/adventurer-sheet.png", spriteSize, sf::Vector2f(WINDOW_HEIGHT/2, WINDOW_WIDTH/2), true, 10);

    //SoundHandler sh("C:/Users/jbcal/Downloads/Cartoon-02.wav");
    //sh.Play();

    //MusicHandler mh("C:/Users/jbcal/Downloads/Cartoon-02.wav", true);
    //mh.Play();

    ParticleSystem ps(1000, 5, 20, window);

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

        window.clear();// sf::Color(255, 255, 255));
        ps.Update(dt);
        ps.Draw();
        window.display();


    }

    return 0;
}
