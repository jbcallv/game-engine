#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"

class Joe {
public:
    
    Joe();
    
    Joe(sf::Vector2f startPosition);

    void Update(float dt);
    
    void Draw(sf::RenderWindow& window);
    
private:
    sf::Vector2f position;
    static constexpr float speed = 30;
    
    bool moving;

    Camera camera;
    int width = WINDOW_WIDTH / 8;
    int height = WINDOW_HEIGHT / 8;

    SpriteSheet animation;
    
    sf::Vector2u getCurrentTileCoordinates();
};

#endif
