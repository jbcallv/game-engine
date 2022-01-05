#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "ParticleSystem.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"

class Joe {
public:
    Joe(sf::Vector2f startPosition);

    void Update(float dt);

    void Draw(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::Vector2f size;
    float speed = 30;

    sf::RectangleShape sprite;
    Camera camera;
    int width = WINDOW_WIDTH / 8;// / 8;
    int height = WINDOW_HEIGHT / 8;// / 8;

    sf::Vector2u getCurrentTileCoordinates();
};

#endif