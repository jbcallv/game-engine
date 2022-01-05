#include "Joe.hpp"

Joe::Joe(sf::Vector2f position) {
	this->position = position;
	size = sf::Vector2f(4, 8);
	camera = Camera(position, sf::Vector2f(width, height));//sf::View(position, sf::Vector2f(width, height));

	sprite = sf::RectangleShape(size);
	sprite.setFillColor(sf::Color(255, 0, 0, 255));
	sprite.setPosition(position);
	sprite.setOrigin(size.x / 2, size.y / 2);
}

void Joe::Update(float dt) {
	// collisions:
	// void pieces will be marked as 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		// moving left
		// get player current tile
		// check tile at col - 1
		// if !tile is (collidable):
		position.x -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		// moving right
		// get player current tile
		// check tile at col + 1
		// if !tile is (collidable):
		position.x += speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		// moving up
		// get player current tile
		// check tile at row - 1
		// if !tile is (collidable):
		position.y -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		// moving down
		// get player current tile
		// check tile at row + 1
		// if !tile is (collidable):
		position.y += speed * dt;

	std::cout << position.x << ", " << position.y + (size.y / 2) << std::endl;
	sprite.setPosition(position);
	camera.Update(position);
}

void Joe::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.setView(camera.view);
}

sf::Vector2u Joe::getCurrentTileCoordinates() {
	// divide position.x by tilemap width
	// divide position.y by tilemap height
	// round to int
	// return value as vector
	return sf::Vector2u(0, 0);
}