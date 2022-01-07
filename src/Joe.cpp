#include "Joe.hpp"
#include <iostream>
#include <string>

Joe::Joe(sf::Vector2f position)
    :
    position(position),
    rightWalk(64,64*3,64,64,"../tests/images/walk-cycle-joe.png"),
    leftWalk(64,64,64,64,"../tests/images/walk-cycle-joe.png"),
    downWalk(64,64*2,64,64,"../tests/images/walk-cycle-joe.png"),
    upWalk(64,0,64,64,"../tests/images/walk-cycle-joe.png")
    {
	this->position = position;
	size = sf::Vector2f(4, 8);
	camera = Camera(position, sf::Vector2f(width, height));//sf::View(position, sf::Vector2f(width, height));

	//sprite = sf::RectangleShape(size);
	//sprite.setFillColor(sf::Color(255, 0, 0, 255));
    
    sf::Texture gettit;
    gettit.loadFromFile("../tests/images/walk-cycle-joe.png");
    texture = gettit;
    sprite = sf::Sprite(texture);
    sprite.setTextureRect({0,0,64,64});
    
	sprite.setPosition(position);
    sprite.setScale(0.3, 0.3);
        
    //Collision
    //wall.setFillColor(sf::Color::Red);
    wall.setSize(sf::Vector2f(100,10));
    wall.setPosition(50,50);
    //sprite.setOrigin(size.x / 2, size.y / 2);
        
    nextBox.setSize(sf::Vector2f(4,8));
    nextBox.setFillColor(sf::Color::Transparent);
    nextBox.setOutlineColor(sf::Color::White);
    nextBox.setOutlineThickness(1.f);
}

void Joe::SetDirection( const sf::Vector2f& dir){
    vel = dir * speed;
}

void Joe::MenuIdle(sf::RenderWindow& window){
    sprite.setPosition({100,500});
    sprite.setScale(4, 4);
    leftWalk.Update(0.002);
    leftWalk.ApplyToSprite(sprite);
    window.draw(sprite);
}

bool Joe::Update(float dt) {
    bool collide = false;
	// collisions:
	// void pieces will be marked as 0
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    {
		// moving left
		// get player current tile
		// check tile at col - 1
		// if !tile is (collidable):
        
        //If sprint held
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dt*=4;
        }
		position.x -= speed * dt;
        leftWalk.Update(dt);
        leftWalk.ApplyToSprite(sprite);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    {
		// moving right
		// get player current tile
		// check tile at col + 1
		// if !tile is (collidable):
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dt*=4;
        }
        position.x += speed * dt;
        rightWalk.Update(dt);
        rightWalk.ApplyToSprite(sprite);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
		// moving up
		// get player current tile
		// check tile at row - 1
		// if !tile is (collidable):
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dt*=4;
        }
		position.y -= speed * dt;
        upWalk.Update(dt);
        upWalk.ApplyToSprite(sprite);
    }
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
		// moving down
		// get player current tile
		// check tile at row + 1
		// if !tile is (collidable):
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
            dt*=4;
        }
        
		position.y += speed * dt;
        downWalk.Update(dt);
        downWalk.ApplyToSprite(sprite);
        }

	//std::cout << position.x << ", " << position.y + (size.y / 2) << std::endl;
    
    
    //Collision Check
    
    sf::FloatRect spriteBounds = sprite.getGlobalBounds();
    sf::FloatRect wallBounds = wall.getGlobalBounds();
    
    nextPos = spriteBounds;
    nextPos.left += position.x;
    nextPos.top += position.y;
    nextBox.setPosition(nextPos.left,nextPos.top);
    
    if (wallBounds.intersects(nextPos)){
        std::cout << "Collision\n" << std::endl;
    }
    
    
    
	sprite.setPosition(position);
	camera.Update(position);
    return collide;
}

void Joe::Draw(sf::RenderWindow& window) {
    sprite.setScale(0.3, 0.3);
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

void Joe::drawHitBox(sf::RenderWindow& window){
    window.draw(nextBox);
}

