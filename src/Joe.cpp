#include "Joe.hpp"

Joe::Joe() {

}

Joe::Joe(sf::Vector2f position) {
    this->position = position;
	// 64-24(gapsize), 64-13(gapsize)
	//size = sf::Vector2u(40, 51);
	size = sf::Vector2u(4, 8);
	box = sf::RectangleShape(this->position);
	box.setSize(sf::Vector2f(size.x, size.y));
	box.setFillColor(sf::Color::Green);

	direction = DOWN;
    //animation = SpriteSheet("../tests/images/player.png", sf::Vector2i(4, 8), sf::Vector2f(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2), false, 0.2f);
    //animation.setGap(sf::Vector2u(24, 13));
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
				//animation.stopAnimation();
			break;
	}
}

void Joe::Update(float dt) {
	// change room1Collisions to a pointer of current level
	// void pieces will be marked as 0
	sf::Vector2u a(position.x / tileSize.x, (position.y+((size.y/3)))/tileSize.y);
	int tileNumber = room1Collisions[(a.x-1) + a.y*(tilemapBounds.x/tileSize.x)];
	std::cout << tileNumber << std::endl;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		sf::Vector2u a(position.x / tileSize.x, (position.y+size.y)/tileSize.y);
		int tileNumber = room1Collisions[(a.x-1) + a.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumber == 0) {
			if (box.getGlobalBounds().intersects(sf::FloatRect(sf::Vector2f((a.x-1)*tileSize.x, a.y*tileSize.y), sf::Vector2f(8, 8))))
				position.x -= speed * dt;
			//animation.resumeAnimation();
		}
		direction = LEFT;
		//animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		sf::Vector2u a(((position.x + (size.x)) / tileSize.x), (position.y+(size.y))/tileSize.y);
		int tileNumber = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumber != 0) {
			position.x += speed * dt;
			//animation.resumeAnimation();
		}
        direction = RIGHT;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		sf::Vector2u a(((position.x + ((size.x/2))) / tileSize.x), (position.y+((size.y/2)))/tileSize.y);
		int tileNumber = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumber != 0) {
			position.y -= speed * dt;
			//animation.resumeAnimation();
		}
		direction = UP;
		//animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		sf::Vector2u a(((position.x + ((size.x/2))) / tileSize.x), (position.y+(size.y))/tileSize.y);
		int tileNumber = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		std::cout << tileNumber << std::endl;
		if (tileNumber != 0) {
			position.y += speed * dt;
			//animation.resumeAnimation();
		}

		direction = DOWN;
	}
	getCurrentTileCoordinates();
	//animation.setAnimation(direction);
	//animation.Update(dt, 0.2f);
	//animation.setPosition(position);
	box.setPosition(position);
}

void Joe::Draw(sf::RenderWindow& window) {
    //window.setView(camera.view);
    //animation.Draw(window);
	window.draw(box);
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

