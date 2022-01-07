#include "Camera.hpp"

Camera::Camera() {

}

Camera::Camera(sf::Vector2f position, sf::Vector2f size) {
    view = sf::View(position, size);
}

void Camera::setBounds(sf::Vector2u bounds) {
    this->bounds = bounds;
}

void Camera::Update(sf::Vector2f playerPosition) {
    if (playerPosition.x + view.getSize().x >= bounds.x && playerPosition.x - view.getSize().y <= 0 &&
        playerPosition.y - view.getSize().y <= 0 && playerPosition.y + view.getSize().y >= bounds.y) {
            view.setCenter(bounds.x / 2, bounds.y / 2);
        }

    // 1600 is right bound of tilemap and 1200 is lower bound of tilemap
    else if (playerPosition.x - view.getSize().x >= 0 && playerPosition.x + view.getSize().x <= bounds.x) {
        // left / right good
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= bounds.y)
            // top / bottom good
            view.setCenter(playerPosition);
        else if (playerPosition.y - view.getSize().y <= 0)
            // top bound
            view.setCenter(playerPosition.x, view.getSize().y);
        else if (playerPosition.y + view.getSize().y >= bounds.y)
            // bottom bound
            view.setCenter(playerPosition.x, bounds.y-view.getSize().y);
    }
    else if (playerPosition.x - view.getSize().x <= 0) {
        // left bound
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= bounds.y) {
            // top / bottom good
            view.setCenter(view.getSize().x, playerPosition.y);
        }
        else if (playerPosition.y - view.getSize().y <= 0) {
            // top bound
            view.setCenter(view.getSize().x, view.getSize().y);
        }
        else if (playerPosition.y + view.getSize().y >= bounds.y) {
            // bottom bound
            view.setCenter(view.getSize().x, bounds.y-view.getSize().y);
        }

    }
    else if (playerPosition.x + view.getSize().x >= bounds.x) {
        // right bound
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= bounds.y)
            // top / bottom good
            view.setCenter(bounds.x-view.getSize().x, playerPosition.y);
        else if (playerPosition.y - view.getSize().y <= 0)
            // top bound
            view.setCenter(bounds.x-view.getSize().x, view.getSize().y);
        else if (playerPosition.y + view.getSize().y >= bounds.y)
            // bottom bound
            view.setCenter(bounds.x-view.getSize().x, bounds.y-view.getSize().y);
    }
}
