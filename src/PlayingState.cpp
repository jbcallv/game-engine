#include "PlayingState.hpp"
#include <iostream>

PlayingState::PlayingState(GameManager& gameManager) : GameState(gameManager) {
    sf::Vector2u tile(8, 8);
    unsigned int mapWidth = 8;
    unsigned int mapHeight = 10;
    sf::Vector2f position((mapWidth*tile.x)/2+10, (mapHeight*tile.y)/2);


    tilemap.load("../tests/images/tileset1.png", room1, tile, mapWidth, mapHeight);
    
    gameMusic.openFromFile("../tests/sounds/Player-II.wav");
    gameMusic.play();

    settings = Gui::Settings({8,8}, {64,80});
    settings.setTexture();

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

void PlayingState::handleEvents(sf::Event& event, sf::RenderWindow& window) {
    // handle joe movement here to enable communication between
    // player, camera, and tilemap
    joe.handleEvents(event);

    if (event.type == sf::Event::MouseButtonPressed) {
        if (settings.settingsButton.isMouseOver(window)) {
            std::cout<<"SETTINGS CLICKED"<<std::endl;
            if (settings.toggleSettings(event, gameMusic)){
                gameMusic.play();
            }
            else{
                gameMusic.pause();
            }
        }
    }
}

void PlayingState::Update(float dt) {
    joe.Update(dt);
    camera.Update(joe.getPosition());
}

void PlayingState::Draw(sf::RenderWindow& window) {
    window.setView(camera.view);
    tilemap.Draw(window);
    joe.Draw(window);
    settings.drawSettings(window);

    if (settings.togSettings){
        settings.showSettingsWindow(window);
    }
}

  