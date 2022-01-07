#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "ParticleSystem.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"
#include "Animation.hpp"

class Joe {
public:
    
    Joe();
    
    Joe(sf::Vector2f startPosition);

    bool Update(float dt);
    
    void SetDirection ( const sf::Vector2f&  dir);

    void Draw(sf::RenderWindow& window);
    
    void MenuIdle(sf::RenderWindow& window);
    
    void drawHitBox(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Vector2f vel = {0.0f,0.0f};
    
    //Collision Testing
    sf::FloatRect nextPos;
    sf::RectangleShape nextBox;
    sf::RectangleShape wall;
    
    static constexpr float speed = 30;

    sf::Sprite sprite;
    sf:: Texture texture;
    Camera camera;
    int width = WINDOW_WIDTH / 8;// / 8;
    int height = WINDOW_HEIGHT / 8;// / 8;
    
    Animation rightWalk;
    Animation leftWalk;
    Animation downWalk;
    Animation upWalk;
    

    sf::Vector2u getCurrentTileCoordinates();
};

#endif
