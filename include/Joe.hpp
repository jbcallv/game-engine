#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "ParticleSystem.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"
//#include "Animation.hpp"

class Joe {
public:
    
    Joe();
    
    Joe(sf::Vector2f startPosition);

    void Update(float dt);
    
    void Draw(sf::RenderWindow& window);
    
    //void MenuIdle(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    static constexpr float speed = 30;

    Camera camera;
    int width = WINDOW_WIDTH / 8;
    int height = WINDOW_HEIGHT / 8;

    SpriteSheet animation;
    
    sf::Vector2u getCurrentTileCoordinates();
};

#endif
