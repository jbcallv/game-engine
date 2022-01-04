#pragma once
#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <iostream>
#include <SFML/Graphics.hpp>

class Camera {
public:
    Camera();

    Camera(sf::Vector2f position, sf::Vector2f size);

    void Update(sf::Vector2f playerPosition);

    sf::View view;
};

#endif