#pragma once
#ifndef MUSIC_HANDLER_HPP
#define MUSIC_HANDLER_HPP

#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

class MusicHandler {
public:
	MusicHandler();

	MusicHandler(std::string audioFilePath, bool loop);

	void Play();

private:
	sf::Music music;

};

#endif