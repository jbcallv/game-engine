#include "Camera.hpp"

Camera::Camera() {
    // duh
}

Camera::Camera(sf::Vector2f position, sf::Vector2f size) {
    view = sf::View(position, size);
}

void Camera::Update(sf::Vector2f playerPosition) {
    if (playerPosition.x - view.getSize().x >= 0 && playerPosition.x + view.getSize().x <= 1600) {
        // left / right good
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= 1200)
            // top / bottom good
            view.setCenter(playerPosition);
        else if (playerPosition.y - view.getSize().y <= 0)
            // top bound
            view.setCenter(playerPosition.x, view.getSize().y);
        else if (playerPosition.y + view.getSize().y >= 1200)
            // bottom bound
            view.setCenter(playerPosition.x, 1200-view.getSize().y);
    }
    else if (playerPosition.x - view.getSize().x <= 0) {
        // left bound
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= 1200) {
            // top / bottom good
            view.setCenter(view.getSize().x, playerPosition.y);
        }
        else if (playerPosition.y - view.getSize().y <= 0) {
            // top bound
            view.setCenter(view.getSize().x, view.getSize().y);
        }
        else if (playerPosition.y + view.getSize().y >= 1200) {
            // bottom bound
            view.setCenter(view.getSize().x, 1200-view.getSize().y);
        }

    }
    else if (playerPosition.x + view.getSize().x >= 1600) {
        // right bound
        if (playerPosition.y - view.getSize().y >= 0 && playerPosition.y + view.getSize().y <= 1200)
            // top / bottom good
            view.setCenter(1600-view.getSize().x, playerPosition.y);
        else if (playerPosition.y - view.getSize().y <= 0)
            // top bound
            view.setCenter(1600-view.getSize().x, view.getSize().y);
        else if (playerPosition.y + view.getSize().y >= 1200)
            // bottom bound
            view.setCenter(1600-view.getSize().x, 1200-view.getSize().y);
    }
}