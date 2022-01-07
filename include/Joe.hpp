#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"
#include "Maps.hpp"

class Joe {
public:
    
    Joe();
    
    Joe(sf::Vector2f startPosition);

    void setBounds(sf::Vector2u bounds);
    void setTileSize(sf::Vector2u tileSize);

    void handleEvents(sf::Event& event);
    void Update(float dt);
    void Draw(sf::RenderWindow& window);

    sf::Vector2f getPosition();
    
private:
    enum directions {LEFT = 1, RIGHT = 3, DOWN = 2, UP = 0};
    directions direction;

    sf::Vector2f position;
    sf::Vector2u size;
    static constexpr float speed = 30;
    
    //SpriteSheet animation;
    sf::RectangleShape box;
    
    sf::Vector2u tilemapBounds;
    sf::Vector2u tileSize;
    sf::Vector2u getCurrentTileCoordinates();
};

#endif
