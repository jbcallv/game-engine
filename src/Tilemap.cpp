#include "Tilemap.hpp"

Tilemap::Tilemap() {
	// default
}

void Tilemap::load(const std::string& tilesetPath, int* tilemap, sf::Vector2u tileSize, unsigned int mapWidth, unsigned int mapHeight) {
	if (!tileset.loadFromFile(tilesetPath))
		std::cout << "Couldn't load tileset file. Please check path and try again.";

	tilemapVertices = sf::VertexArray(sf::Quads, mapWidth * mapHeight * 4);

	for (unsigned int i = 0; i < mapWidth; i++) {
		for (unsigned int j = 0; j < mapHeight; j++) {
			int tileNumber = tilemap[i + j * mapWidth];

			int textureX = tileNumber % (tileset.getSize().x / tileSize.x);
			int textureY = tileNumber / (tileset.getSize().x / tileSize.x);

			sf::Vertex* quad = &tilemapVertices[(i + j * mapWidth) * 4];

			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i+1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i+1) * tileSize.x, (j+1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j+1) * tileSize.y);

			if (tileNumber) {
				quad[0].texCoords = sf::Vector2f(textureX * tileSize.x, textureY * tileSize.y);
				quad[1].texCoords = sf::Vector2f((textureX+1) * tileSize.x, textureY * tileSize.y);
				quad[2].texCoords = sf::Vector2f((textureX+1) * tileSize.x, (textureY+1) * tileSize.y);
				quad[3].texCoords = sf::Vector2f(textureX * tileSize.x, (textureY+1) * tileSize.y);
			}

		}
	}
}

void Tilemap::Draw(sf::RenderWindow& window) {
	sf::RenderStates states(&tileset);
	window.draw(tilemapVertices, states);
}