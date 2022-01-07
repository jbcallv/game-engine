#include "PlayingState.hpp"
#include <iostream>

PlayingState::PlayingState(GameManager& gameManager) : GameState(gameManager) {
    sf::Vector2f position(0, 0);
    sf::Vector2u tile(8, 8);
    unsigned int mapWidth = 8;
    unsigned int mapHeight = 10;

    tilemap.load("../tests/images/tileset1.png", room1, tile, mapWidth, mapHeight);

    joe = Joe(position);
    joe.setBounds(sf::Vector2u(tile.x*mapWidth, tile.y*mapHeight));
    joe.setTileSize(tile);
    
    camera = Camera(position, sf::Vector2f(CAMERA_WIDTH, CAMERA_HEIGHT));
    camera.setBounds(sf::Vector2u(tile.x*mapWidth, tile.y*mapHeight));
}

PlayingState::~PlayingState() {

}

void PlayingState::pause() {

}

void PlayingState::resume() {

}

void PlayingState::handleEvents(sf::Event& event, sf::RenderWindow& wnidow) {
    // handle joe movement here to enable communication between
    // player, camera, and tilemap
    joe.handleEvents(event);
}

void PlayingState::Update(float dt) {
    joe.Update(dt);
    camera.Update(joe.getPosition());
}

void PlayingState::Draw(sf::RenderWindow& window) {
    window.setView(camera.view);
    tilemap.Draw(window);
    joe.Draw(window);
}
