#include "MenuState.hpp"

MenuState::MenuState(GameManager& gameManager) : GameState(gameManager) {
    menuText = "Click the blue button";
    std::string buttonText = "Start";

    introMusic.openFromFile("../tests/sounds/6pm.wav");
    introMusic.play();
    
    menuButton = Gui::Button(buttonText, {1000,400}, 50, sf::Color(91, 193, 240), sf::Color::Red, {500,500});
    sf::Font f;
    f.loadFromFile("../tests/fonts/manaspc.ttf");

    
}

MenuState::~MenuState() {

}

void MenuState::pause() {

}

void MenuState::resume() {

}

void MenuState::handleEvents(sf::Event& event, sf::RenderWindow& window) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (menuButton.isMouseOver(window)) {
            // fade out music by decreasing volume
            introMusic.stop();
            gameManager.changeState(std::unique_ptr<GameState>(new PlayingState(gameManager)));
        }
    }
    if (event.type == sf::Event::MouseMoved){
        if (menuButton.isMouseOver(window))
            menuButton.setBackColor(sf::Color(46, 60, 217));
    
        else
            menuButton.setBackColor(sf::Color(91, 193, 240));
    }
}

void MenuState::Update(float dt) {

}

void MenuState::Draw(sf::RenderWindow& window) {
    Gui::TextSystem mt(menuText, "../tests/fonts/manaspc.ttf", sf::Color::White, 25, 300.0f, 300.0f);
    menuButton.drawTo(window);
    mt.drawText(window);
}