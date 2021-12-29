#pragma once
#ifndef PARTICLE_SYSTEM_HPP
#define PARTICLE_SYSTEM_HPP

#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>

// code based on the implementation in Dave Churchill's video: https://www.youtube.com/watch?v=A0-UOZ2v4V8
// and SFML's tutorial on vertex arrays: https://www.sfml-dev.org/tutorials/2.5/graphics-vertex-array.php
class ParticleSystem {
public:
	ParticleSystem();

	ParticleSystem(std::size_t totalParticles, int size, float maxLifetime, sf::RenderWindow& window);

	void Update(float dt);

	void Draw();

private:
	// determine optimal order
	struct Particle {
		sf::Vector2f velocity;
		float lifetime = 0;
	};

	sf::RenderWindow* window;
	std::vector<Particle> particlePool;
	sf::VertexArray particleVertices;
	float particleSize = 10;
	float maxLifetime = 10;

	void resetParticle(std::size_t index);
};

#endif
