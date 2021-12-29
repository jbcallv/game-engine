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
	* delay is in ms
	*/
	void Play(int delay);

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
