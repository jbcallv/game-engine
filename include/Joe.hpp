#pragma once
#ifndef JOE_HPP
#define JOE_HPP

#include <SFML/Graphics.hpp>
#include "ParticleSystem.hpp"
#include "SpriteSheet.hpp"

class Joe {
public:
    Joe(sf::Vector2f startPosition);

    void Update(float dt);

    void Draw(sf::RenderWindow& window);

private:
    sf::Vector2f position;
    sf::Vector2f size;
    float speed = 200;

    sf::RectangleShape sprite;
};

#endif