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
	// 0 is a collidable tile
	// change room1Collisions to a pointer of current level
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		// a is top left and b is bottom left
		sf::Vector2u a(position.x/tileSize.x, (position.y+size.y/2)/tileSize.y);
		sf::Vector2u b(position.x/tileSize.x, (position.y+size.y-0.1)/tileSize.y);
		int tileNumberA = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		int tileNumberB = room1Collisions[(b.x) + b.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumberA != 0 && tileNumberB != 0 && position.x >= 0) {
			position.x -= speed * dt;
			//animation.resumeAnimation();
		}
		direction = LEFT;
		//animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		sf::Vector2u a((position.x+size.x)/tileSize.x, (position.y+size.y/2)/tileSize.y);
		sf::Vector2u b((position.x+size.x)/tileSize.x, (position.y+size.y-0.1)/tileSize.y);
		int tileNumberA = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		int tileNumberB = room1Collisions[(b.x) + b.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumberA != 0 && tileNumberB != 0 && position.x+size.x <= tilemapBounds.x) {
			position.x += speed * dt;
			//animation.resumeAnimation();
		}
        direction = RIGHT;
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		sf::Vector2u a((position.x+0.1)/tileSize.x, (position.y+size.y/3)/tileSize.y);
		sf::Vector2u b((position.x+size.x-0.1)/tileSize.x, (position.y+size.y/3)/tileSize.y);
		int tileNumberA = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		int tileNumberB = room1Collisions[(b.x) + b.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumberA != 0 && tileNumberB != 0 && position.y >= 0) {
			position.y -= speed * dt;
			//animation.resumeAnimation();
		}
		direction = UP;
		//animation.resumeAnimation();
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		sf::Vector2u a((position.x+0.1)/tileSize.x, (position.y+size.y)/tileSize.y);
		sf::Vector2u b((position.x+size.x-0.1)/tileSize.x, (position.y+size.y)/tileSize.y);
		int tileNumberA = room1Collisions[(a.x) + a.y*(tilemapBounds.x/tileSize.x)];
		int tileNumberB = room1Collisions[(b.x) + b.y*(tilemapBounds.x/tileSize.x)];
		if (tileNumberA != 0 && tileNumberB != 0 && position.y+size.y <= tilemapBounds.y) {
			position.y += speed * dt;
			//animation.resumeAnimation();
		}
		direction = DOWN;
	}
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