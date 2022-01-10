#include <SFML/Graphics.hpp>
#include <string>
#include <vector>
#include <iostream>
#include "TextSystem.hpp"
#include "Button.hpp"
#include "Joe.hpp"
#include "Menu.hpp"

Menu::Menu(){
        
    menuText = "Click the blue button";
    std::string buttonText = "Start";
    
    menuButton = Button(buttonText, {1000,400}, 50, sf::Color::White, sf::Color::Red);
    menuButton.setPosition({500,500});
    sf::Font f;
    f.loadFromFile("/Users/williamkyle/Desktop/font.ttf");
    menuButton.setFont(f);
}

bool Menu::MenuWhile(sf::RenderWindow& window, sf::Event event){
    if (event.type == sf::Event::MouseButtonPressed){
        if (menuButton.isMouseOver(window)){
            return false;
        }
    }
    
    if (event.type == sf::Event::MouseMoved){
        if (menuButton.isMouseOver(window)){
            menuButton.setBackColor(sf::Color(46, 60, 217));
        }
    
        else
            menuButton.setBackColor(sf::Color(91, 193, 240));
        }
    return true;
}
    
void Menu::MenuDraw(sf::RenderWindow &window){
    TextSystem mt = TextSystem(menuText,"/Users/williamkyle/Desktop/font.ttf",sf::Color::White,25,300.0,300.0);
    menuButton.drawTo(window);
    mt.drawText(window);
}

