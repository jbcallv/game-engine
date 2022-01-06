#include "Joe.hpp"

Joe::Joe(sf::Vector2f position) {
    this->position = position;
    animation = SpriteSheet("../tests/images/adventurer-sheet.png", sf::Vector2i(50, 37));
	camera = Camera(position, sf::Vector2f(width, height));
}

void Joe::Update(float dt) {
	// collisions:
	// void pieces will be marked as 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		// moving left
		// get player current tile
		// check tile at col - 1
		// if !tile is (collidable):
		position.x -= speed * dt;
        animation.setAnimation(1);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		// moving right
		// get player current tile
		// check tile at col + 1
		// if !tile is (collidable):
        position.x += speed * dt;
        animation.setAnimation(3);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		// moving up
		// get player current tile
		// check tile at row - 1
		// if !tile is (collidable):
		position.y -= speed * dt;
        animation.setAnimation(0);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		// moving down
		// get player current tile
		// check tile at row + 1
		// if !tile is (collidable):
		position.y += speed * dt;
        animation.setAnimation(3);
        }

    animation.Update(dt, 0.2f);
    animation.setPosition(position);
	camera.Update(position);
}

void Joe::Draw(sf::RenderWindow& window) {
	//window.draw(sprite);
	window.setView(camera.view);
    animation.Draw(window);
}

sf::Vector2u Joe::getCurrentTileCoordinates() {
	// divide position.x by tilemap width
	// divide position.y by tilemap height
	// round to int
	// return value as vector
	return sf::Vector2u(0, 0);
}

