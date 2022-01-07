#include "Joe.hpp"

Joe::Joe() {

}

Joe::Joe(sf::Vector2f position) {
    this->position = position;

	direction = DOWN;
    animation = SpriteSheet("../tests/images/walk-cycle.png", sf::Vector2i(64, 64), sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), true, 0.3f);
    animation.setGap(sf::Vector2u(24, 13));
<<<<<<< HEAD
    moving = true;
    
    
=======
}

void Joe::handleEvents(sf::Event& event) {
	switch (event.type) {
		case sf::Event::KeyReleased:
			if (event.key.code == sf::Keyboard::A || event.key.code == sf::Keyboard::S ||
			event.key.code == sf::Keyboard::D || event.key.code == sf::Keyboard::W)
				animation.stopAnimation();
			break;
	}
>>>>>>> e4cc7684d36bc3205f96b516a5092759c4803515
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
		direction = LEFT;
		animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		// moving right
		// get player current tile
		// check tile at col + 1
		// if !tile is (collidable):
        position.x += speed * dt;
		direction = RIGHT;
		animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		// moving up
		// get player current tile
		// check tile at row - 1
		// if !tile is (collidable):
		position.y -= speed * dt;
		direction = UP;
		animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		// moving down
		// get player current tile
		// check tile at row + 1
		// if !tile is (collidable):
		position.y += speed * dt;
		direction = DOWN;
		animation.resumeAnimation();
    }
	animation.setAnimation(direction);
	animation.Update(dt, 0.2f);
	animation.setPosition(position);
}

void Joe::Draw(sf::RenderWindow& window) {
    //window.setView(camera.view);
    animation.Draw(window);
}

sf::Vector2f Joe::getPosition() {
	return position;
}

sf::Vector2u Joe::getCurrentTileCoordinates() {
	// divide position.x by tilemap width
	// divide position.y by tilemap height
	// round to int
	// return value as vector
	return sf::Vector2u(0, 0);
}

