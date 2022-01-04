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
    float speed = 300;

    sf::RectangleShape sprite;
    //sf::View camera;
    Camera camera;
    int width = WINDOW_WIDTH / 4;
    int height = WINDOW_HEIGHT / 4;
};

#endif