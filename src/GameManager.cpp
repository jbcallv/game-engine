#include "GameManager.hpp"

GameManager::GameManager(sf::RenderWindow& window) : window(window) {
    //srand(time(NULL));
}

GameManager::~GameManager() {
    // pop everything from heap
    while (!states.empty()) {
        states.pop();
    }

    window.close();
}

void GameManager::changeState(std::unique_ptr<GameState> state) {
    if (!states.empty())
        states.pop();
    pushState(std::move(state));
}

void GameManager::pushState(std::unique_ptr<GameState> state) {
    if (!states.empty())
        states.top()->pause();

    state->resume();
    states.push(std::move(state));
}

void GameManager::popState() {
    if (!states.empty()) {
        states.pop();
        states.top()->resume();
    }
}

void GameManager::gameLoop() {
    while (running && window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            this->handleEvents(event);
        }

        time = clock.restart();
        dt = time.asSeconds();

        window.clear();
        Update(dt);
        Draw();
        window.display();
    }
}

void GameManager::handleEvents(sf::Event& event) {
    if (event.type == sf::Event::Closed) {
        running = false;
        window.close();
    }
    
    states.top()->handleEvents(event, window);
}

void GameManager::Update(float dt) {
    states.top()->Update(dt);
}

void GameManager::Draw() {
    states.top()->Draw(window);
}