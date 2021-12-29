#pragma once
#ifndef SOUND_HANDLER_HPP
#define SOUND_HANDLER_HPP

#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

class SoundHandler {
public:
	SoundHandler();

	SoundHandler(std::string audioFilePath);

	void Play();

private:
	sf::SoundBuffer buffer;
	sf::Sound sound;

	sf::Music music;
};

#endif
