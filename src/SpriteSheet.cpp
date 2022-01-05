#include "SpriteSheet.hpp"

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

void SpriteSheet::setAnimation(unsigned int animationNumber) {
	location.x = animationNumber;
}

void SpriteSheet::setSprite(sf::Sprite& sprite, sf::Vector2i location) {
	// set the sprite to the one at row, column to position.x, position.y respectively
	sprite.setTextureRect(sf::IntRect(sf::Vector2i(location.y*spriteSize.x, location.x*spriteSize.y), spriteSize));
}

void SpriteSheet::nextSprite() {
	if (location.y >= dimensions.y) {
		location.y = 0;
		setSprite(sprite, location);
		return;
	}
	
	// continue going to next sprite
	setSprite(sprite, location);
	location.y += 1;
}

void SpriteSheet::Update(float dt, float delay) {
	time += dt;
	if (time >= delay) {
		nextSprite();
		time = 0;
	}
}

void SpriteSheet::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
}