#include "SpriteSheet.hpp"
#include <iostream>
#include <thread>


SpriteSheet::SpriteSheet(std::string spriteSheetPath, sf::Vector2i spriteSize, sf::Vector2f position, 
	bool trueCenter, float scale, float rotation) {

	this->spriteSize = spriteSize;

	if (!spriteSheet.loadFromFile(spriteSheetPath)) {
		std::cout << "Failed to load sprite sheet. Check path and try again." << std::endl;
	}

	// get number of rows and columns in sprite sheet
	dimensions.x = spriteSheet.getSize().y / spriteSize.y;
	dimensions.y = spriteSheet.getSize().x / spriteSize.x;
	
	// set sprite start values
	if (trueCenter) sprite.setOrigin(spriteSize.x / 2, spriteSize.y / 2);
	sprite.setTexture(spriteSheet);
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), spriteSize));
	sprite.setScale(scale, scale);
	sprite.setRotation(rotation);
	sprite.setPosition(position);

	// store position of sprite
	location = sf::Vector2i(sprite.getTextureRect().top / spriteSize.y, sprite.getTextureRect().left / spriteSize.x);
}

void SpriteSheet::setSprite(sf::Sprite& sprite, sf::Vector2i location) {
	// set the sprite to the one at row, column to position.x, position.y respectively
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(location.y*spriteSize.x, location.x*spriteSize.y), spriteSize));
}

void SpriteSheet::nextSprite() {
	// get current row, column of sprite
	if (location.y >= dimensions.y && location.x < dimensions.x) {
		// go to next row and start at first column
		location.x += 1;
		location.y = 0;
		setSprite(sprite, location);
		return;
	}

	else if (location.x >= dimensions.x && location.y >= dimensions.y) {
		// restart at first sprite
		location.x = 0;
		location.y = 0;
		setSprite(sprite, location);
		return;
	}
	
	// continue going to next sprite
	setSprite(sprite, location);
	location.y += 1;
}

void SpriteSheet::Play(int delay) {
	// implement your own version of this
	//std::this_thread::sleep_for(std::chrono::milliseconds(delay));
	nextSprite();
}

void SpriteSheet::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
}