#pragma once
#ifndef TEXT_SYSTEM_HPP
#define TEXT_SYSTEM_HPP

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

class TextSystem {
    
private:
    sf::Font font;
    sf::Text text;

public:
    TextSystem(std::string words, std::string path, sf::Color color, int size, float x, float y);
        
    sf::Text getText() { return text; }
    
};

#endif
