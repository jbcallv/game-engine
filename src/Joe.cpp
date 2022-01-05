#include "Joe.hpp"

Joe::Joe(sf::Vector2f position) {
	this->position = position;
	size = sf::Vector2f(4, 7);
	camera = Camera(position, sf::Vector2f(width, height));//sf::View(position, sf::Vector2f(width, height));

	sprite = sf::RectangleShape(size);
	sprite.setFillColor(sf::Color(255, 0, 0, 255));
	sprite.setPosition(position);
	sprite.setOrigin(size.x / 2, size.y / 2);
}

void Joe::Update(float dt) {
	// collisions:
	// 1) calculate the tile the player is on / going to stand on
	// 2) get the tile's number value and check if it's constant represetnting collidable
	// 3) if so, don't let player walk on it etc etc.
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		position.x -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		position.x += speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		position.y -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		position.y += speed * dt;

	sprite.setPosition(position);
	camera.Update(position);
}

void Joe::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.setView(camera.view);
}