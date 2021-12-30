#include "Tilemap.hpp"

Tilemap::Tilemap() {
	// default
}

bool Tilemap::load(const std::string& tilesetPath, const std::string& tilemapPath, sf::Vector2u tileSize, unsigned int mapWidth, unsigned int mapHeight) {
	if (!tileset.loadFromFile(tilesetPath))
		return false;

	tilemapVertices = sf::VertexArray(sf::Quads, mapWidth * mapHeight * 4);

	// populate the vertex array with two for loops for rows and columns
	// to parse tmx files: 
		// 1) rows should be separated by \n characters
		// 2) numbers in the file represent the corresponding tile from the tileset
	for (int i = 0; i < mapWidth; i++) {
		for (int j = 0; j < mapHeight; j++) {

		}
	}

	return true;
}

void Tilemap::Draw(sf::RenderWindow& window) {
	window.draw(tilemapVertices);
}