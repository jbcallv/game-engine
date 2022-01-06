#include "MenuState.hpp"

MenuState::MenuState(GameManager& gameManager) : GameState(gameManager) {
    menuText = "Click the blue button";
    std::string buttonText = "Start";
    
    menuButton = Button(buttonText, {1000,400}, 50, sf::Color::Blue, sf::Color::Red);
    menuButton.setPosition({500,500});
    sf::Font f;
    f.loadFromFile("../tests/fonts/manaspc.ttf");
    menuButton.setFont(f);
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
            gameManager.changeState(std::unique_ptr<GameState>(new PlayingState(gameManager)));
        }
    }
}

void MenuState::Update(float dt) {

}

void MenuState::Draw(sf::RenderWindow& window) {
    TextSystem mt = TextSystem(menuText, "../tests/fonts/manaspc.ttf", sf::Color::White, 25, 300.0f, 300.0f);
    menuButton.drawTo(window);
    mt.drawText(window);
}


/*bool Menu::MenuWhile(sf::RenderWindow& window, sf::Event event){
    if (event.type == sf::Event::MouseButtonPressed){
        if (menuButton.isMouseOver(window)){
            return false;
        }
    }
    
    if (event.type == sf::Event::MouseMoved){
        if (menuButton.isMouseOver(window)){
            menuButton.setBackColor(sf::Color(46, 60, 217));
        }
    
        else
            menuButton.setBackColor(sf::Color(91, 193, 240));
        }
    return true;
}
    
void Menu::MenuDraw(sf::RenderWindow &window){
    TextSystem mt = TextSystem(menuText,"/Users/williamkyle/Desktop/font.ttf",sf::Color::White,25,300.0,300.0);
    menuButton.drawTo(window);
    mt.drawText(window);
}*/

