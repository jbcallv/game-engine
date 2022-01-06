#include "Animation.hpp"
#include <chrono>

Animation::Animation(int x, int y, int width, int height) {
    texture.loadFromFile("../tests/images/walk-cycle.png");
    for (int i = 0; i < nFrames; i++)
    {
        frames[i] = { x + i * width, y, width-27, height-13 };
    }
}

void Animation::ApplyToSprite(sf::Sprite& s) const{
    s.setTexture(texture);
    s.setTextureRect(frames[iFrame]);
}

void Animation::Update(float dt){
    time += dt;
    while (time>= holdTime){
        time -= holdTime;
        Advance();
    }
}

void Animation::Advance(){
    if (++iFrame >= nFrames){
        iFrame = 0;
    }
}