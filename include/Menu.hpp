#pragma once
#ifndef MENU_HPP
#define MENU_HPP
#include <iostream>
#include <SFML/Graphics.hpp>
#include <string>
#include <vector>

#include "TextSystem.hpp"
#include "Button.hpp"
#include "Joe.hpp"


class Menu {
public:
    Menu();
    
    bool MenuWhile(sf::RenderWindow& window, sf::Event event);
    
    void MenuDraw(sf::RenderWindow& window);

private:
    Button menuButton;
    std::string menuText;
    
};

#endif
