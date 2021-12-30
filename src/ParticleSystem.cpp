#include "ParticleSystem.hpp"

ParticleSystem::ParticleSystem(std::size_t totalParticles, int size, float maxLifetime, sf::RenderWindow& window) {

	particlePool = std::vector<Particle>(totalParticles);
	particleVertices = sf::VertexArray(sf::Quads, totalParticles * 4);
	particleSize = size;
	this->maxLifetime = maxLifetime;
	this->window = &window;

	for (int i = 0; i < particlePool.size(); i++) {
		resetParticle(i);
	}
}

void ParticleSystem::Update(float dt) {
	for (std::size_t i = 0; i < particlePool.size(); i++) {

		if (particlePool[i].lifetime <= 0)
			resetParticle(i);

		particleVertices[i * 4 + 0].position += particlePool[i].velocity * dt;
		particleVertices[i * 4 + 1].position += particlePool[i].velocity * dt;
		particleVertices[i * 4 + 2].position += particlePool[i].velocity * dt;
		particleVertices[i * 4 + 3].position += particlePool[i].velocity * dt;

		// taken from sfml docs to make particles fade
		float ratio = particlePool[i].lifetime / 4;
		particleVertices[i].color.a = static_cast<sf::Uint8>(ratio * 255);

		// need a scalar here to adjust speed
		particlePool[i].lifetime -= (rand() % 10 + 1) * dt;
	}
}

void ParticleSystem::Draw() {
	for (int i = 0; i < particlePool.size(); i++) {
		this->window->draw(particleVertices);
	}
}

void ParticleSystem::resetParticle(std::size_t index) {
	// position is emitter location
	float mouseX = sf::Mouse::getPosition(*this->window).x;
	float mouseY = sf::Mouse::getPosition(*this->window).y;
	particleVertices[index * 4 + 0].position = sf::Vector2f(mouseX, mouseY);
	particleVertices[index * 4 + 1].position = sf::Vector2f(mouseX+particleSize, mouseY);
	particleVertices[index * 4 + 2].position = sf::Vector2f(mouseX+particleSize, mouseY+particleSize);
	particleVertices[index * 4 + 3].position = sf::Vector2f(mouseX, mouseY+particleSize);

	// color can be changed here
	sf::Color color(0, rand()%255, 100, rand() % 255);
	particleVertices[index * 4 + 0].color = color;
	particleVertices[index * 4 + 1].color = color;
	particleVertices[index * 4 + 2].color = color;
	particleVertices[index * 4 + 3].color = color;

	float vx = ((float)rand() / RAND_MAX) * 300 - 150;
	float vy = ((float)rand() / RAND_MAX) * 300 - 150;
	particlePool[index].velocity = sf::Vector2f(vx, vy);

	particlePool[index].lifetime = rand() % 5 + 2.5;
}
