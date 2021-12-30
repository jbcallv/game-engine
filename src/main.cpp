#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "Constants.hpp"
#include "SpriteSheet.hpp"
#include "SoundHandler.hpp"
#include "MusicHandler.hpp"
#include "ParticleSystem.hpp"
#include "TextSystem.hpp"
#include "TextBox.hpp"
#include "Button.hpp"
#include "Joe.hpp"

int main()
{
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Game Engine Test", sf::Style::Titlebar | sf::Style::Close);

    sf::Clock clock;
    sf::Time time;
    float dt = 0;

    // for testing purposes only
    /*sf::Vector2i spriteSize(50, 37);
    SpriteSheet ss("../tests/images/adventurer-sheet.png", spriteSize, sf::Vector2f(WINDOW_WIDTH/2, WINDOW_HEIGHT/2), true, 10);

    MusicHandler mh("../tests/sounds/sound.wav", true);
    mh.Play();
    
    // let's do this in the textsystem
    sf::Font font;
    if (!font.loadFromFile("../tests/fonts/manaspc.ttf"))
    {
        std::cout << "Coudln't get that font, try again." << std::endl;
    }
 
    TextSystem bs("Feel free to type stuff on your keyboard.", "../tests/fonts/manaspc.ttf", sf::Color(211,211,211), 25, 50.0, 200.0);
    
    Textbox textbox(100, sf::Color::White, true);
    textbox.setFont(font);
    textbox.setPosition({ 50, 400 });
    
    Button button1("Click here", { 170, 50 }, 17, sf::Color(102, 102, 51), sf::Color::Black);
    button1.setFont(font);
    button1.setPosition(sf::Vector2f(50,100));
    
    Button button2("No, click here", { 170, 50 }, 17, sf::Color(102, 102, 51), sf::Color::Black);
    button2.setFont(font);
    button2.setPosition(sf::Vector2f(300,100));

    ParticleSystem ps(1000, 5, 20, window);*/

    Joe joe(sf::Vector2f(WINDOW_WIDTH, 0));

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
            
            /*else if (event.type == sf::Event::TextEntered)
                textbox.typedOn(event);
            
            else if (event.type == sf::Event::MouseMoved){
                // Main menu:
                if (button1.isMouseOver(window)) {
                    // Highlight buttons when mouse is over them:
                    button1.setBackColor(sf::Color(153, 204, 0));
                }
                else {
                    button1.setBackColor(sf::Color(102, 102, 51));
                }
                if (button2.isMouseOver(window)) {
                    // Highlight buttons when mouse is over them:
                    button2.setBackColor(sf::Color(153, 204, 0));
                }
                else {
                    button2.setBackColor(sf::Color(102, 102, 51));
                }
            }*/
            
        }

        time = clock.restart();
        dt = time.asSeconds();

        window.clear();
        joe.Update(dt);
        joe.Draw(window);

        window.display();

        /*ps.Update(dt);
        ss.Play(3);

        ss.Draw(window);
        ps.Draw();
        
        //window.draw(ts.getText());
        window.draw(bs.getText());
        textbox.drawTo(window);
        button1.drawTo(window);
        button2.drawTo(window);*/
        //window.display();
    }

    return 0;
}
