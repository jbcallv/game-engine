#include "Joe.hpp"

Joe::Joe() {

}

Joe::Joe(sf::Vector2f position) {
    this->position = position;
	// 64-24(gapsize), 64-13(gapsize)
	size = sf::Vector2u(40, 51);

	direction = DOWN;
    animation = SpriteSheet("../tests/images/walk-cycle.png", sf::Vector2i(64, 64), sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), false, 0.2f);
    animation.setGap(sf::Vector2u(24, 13));
<<<<<<< HEAD
    moving = true;
    
    
=======
}

void Joe::setBounds(sf::Vector2u bounds) {
	tilemapBounds = bounds;
}

void Joe::setTileSize(sf::Vector2u tileSize) {
	this->tileSize = tileSize;
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
	//std::cout << room1[a.x + a.y*(tilemapBounds.x/tileSize.x)] - 1 << std::endl;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		// moving left
		// get player current tile
		
		// check tile at col - 1
		// if !tile is (collidable):
		sf::Vector2u a(position.x / tileSize.x, (position.y+((size.y)*0.2f))/tileSize.y);
		int tileNumber = room1[(a.x) + a.y*(tilemapBounds.x/tileSize.x)] - 1;
		if (tileNumber != 5 && tileNumber != 6) {
			position.x -= speed * dt;
			animation.resumeAnimation();
		}

		direction = LEFT;
		//animation.resumeAnimation();
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
	getCurrentTileCoordinates();
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
	int x = (position.x + ((size.x/2)*0.2f)) / tileSize.x;
	int y = (position.y + (size.y*0.2f)) / tileSize.y;

	//std::cout << position.x << ", " << position.y+(size.y*0.3f) << std::endl;
	// return value as vector
	return sf::Vector2u(x, y);
}

