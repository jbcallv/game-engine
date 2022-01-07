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

    void handleEvents(sf::Event& event);
    void Update(float dt);
    void Draw(sf::RenderWindow& window);
    
private:
    enum directions {LEFT = 1, RIGHT = 3, DOWN = 2, UP = 0};
    directions direction;

    sf::Vector2f position;
    static constexpr float speed = 30;
    
    Camera camera;
    int width = WINDOW_WIDTH / 8;
    int height = WINDOW_HEIGHT / 8;

    SpriteSheet animation;
    
    sf::Vector2u getCurrentTileCoordinates();
};

#endif
