#include "Joe.hpp"

Joe::Joe(sf::Vector2f position) {
	this->position = position;
	size = sf::Vector2f(10, 20);
	camera = sf::View(position, sf::Vector2f(WINDOW_WIDTH/3, WINDOW_HEIGHT/3));

	sprite = sf::RectangleShape(size);
	sprite.setFillColor(sf::Color(255, 0, 0, 255));
	sprite.setPosition(position);
	sprite.setOrigin(size.x / 2, size.y / 2);
}

void Joe::Update(float dt) {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		position.x -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		position.x += speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		position.y -= speed * dt;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		position.y += speed * dt;

	sprite.setPosition(position);
	camera.setCenter(position);
}

void Joe::Draw(sf::RenderWindow& window) {
	window.draw(sprite);
	window.setView(camera);
}