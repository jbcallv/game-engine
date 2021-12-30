#include "TextSystem.hpp"

TextSystem::TextSystem(std::string words, std::string path, sf::Color color, int size, float x, float y) {
    sf::Font f;
    if (!f.loadFromFile(path))
    {
        std::cout << "Coudln't get that font, try again." << std::endl;
    }
    
    font = f;
    
    sf::Text t;
    t.setFont(font);
    t.setString(words);
    t.setCharacterSize(size);
    t.setFillColor(color);
    t.setPosition(x,y);
    text = t;
}

