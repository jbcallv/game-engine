#pragma once
#ifndef ANIMATION_HPP
#define ANIMATION_HPP

#include <SFML/Graphics.hpp>
#include "Constants.hpp"
#include "ParticleSystem.hpp"
#include "SpriteSheet.hpp"
#include "Camera.hpp"

class Animation {
public:
    Animation(int x, int y, int width, int height, std::string path);
    void ApplyToSprite(sf::Sprite& s) const;
    void Update(float dt);
    

private:
    static constexpr int nFrames = 8;
    static constexpr float holdTime = 0.1f;
    sf::Texture texture;
    sf::IntRect frames[nFrames];
    int iFrame = 0;
    float time = 0.0f;
    void Advance();
};

#endif


