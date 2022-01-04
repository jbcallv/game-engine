#pragma once
#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>

// code made from sfml's vertex array tutorial: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
class Tilemap {
public:
	Tilemap();

	void load(const std::string& tilesetPath, int* tilemap, sf::Vector2u tileSize, unsigned int mapWidth, unsigned int mapHeight);

	void Draw(sf::RenderWindow& window);

private:
	sf::VertexArray tilemapVertices;
	sf::Texture tileset;
};

#endif