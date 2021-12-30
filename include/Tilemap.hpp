#pragma once
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <string>
#include <SFML/Graphics.hpp>

// code heavily based on sfml's vertex array tutorial: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
// we'll be loading tmx format tilemaps
class Tilemap {
public:
	Tilemap();

	bool load(const std::string& tilesetPath, const std::string& tilemapPath, unsigned int tileWidth, unsigned int tileHeight);

	void Draw(sf::RenderWindow& window);

private:
	sf::VertexArray tilemapVertices;
	sf::Texture tileset;
};

#endif