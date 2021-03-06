#pragma once
#ifndef SPRITE_SHEET_HPP
#define SPRITE_SHEET_HPP

#include <iostream>
#include <string>

#include <SFML/Graphics.hpp>

#include <thread>
#include <chrono>

class SpriteSheet {
public:
	SpriteSheet();

	SpriteSheet(std::string spriteSheetPath, sf::Vector2i spriteSize, sf::Vector2f position=sf::Vector2f(0, 0), 
		bool trueCenter=false, float scale=1.0, float rotation=0.0);

	/*
	* since each row is an animation, this method
	* sets the animation to the given row number.
	* Uses 0 based indexing, hopefully
	*/
	void setAnimation(unsigned int animationNumber);

	/*
	* allows us to move the sprite
	*/
	void setPosition(sf::Vector2f position);

	/*
	* sets the gap size between each frame in
	* the sprite sheet
	*/
	void setGap(sf::Vector2u gapSize);

	/*
	* puts animation at first frame and stops
	*/
	void stopAnimation();

	/*
	* allows animation to continue
	*/
	void resumeAnimation();

	/*
	* delay is in seconds
	*/
	void Update(float dt, float delay);

	/*
	* draws the current sprite on the window
	*/
	void Draw(sf::RenderWindow& window);

private:
	sf::Vector2i spriteSize;
	sf::Vector2i dimensions;
	sf::Vector2i location;
	sf::Texture spriteSheet;
	sf::Sprite sprite;

	sf::Vector2u gapSize;

	/*
	* for updating
	*/
	float time = 0;
	bool playing = false;

	/*
	* goes to the next sprite in the sheet
	*/
	void nextSprite();

	/*
	* sets the sprite to row position.x and column position.y in the
	* sheet
	*/
	void setSprite(sf::Sprite& sprite, sf::Vector2i location);
};

#endif
