#include "PlayingState.hpp"

PlayingState::PlayingState(GameManager& gameManager) : GameState(gameManager) {
    joe = Joe(sf::Vector2f(32, 40));
    tilemap.load("../tests/images/tileset1.png", room1, sf::Vector2u(8, 8), 8, 10);
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
}

void PlayingState::Draw(sf::RenderWindow& window) {
    tilemap.Draw(window);
    joe.Draw(window);
}
