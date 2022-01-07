#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera();

    Camera(sf::Vector2f position, sf::Vector2f size);

    void setBounds(sf::Vector2u bounds);

    void Update(sf::Vector2f playerPosition);

    sf::View view;

private:
    /*
    * bounds.x is width of tilemap
    * bounds.y is height of tilemap
    */
    sf::Vector2u bounds;
};

#endif