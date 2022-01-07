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

	void load(const std::string& audioFilePath);

	void Play();

	void Stop();

private:
    sf::Music music;

};

#endif
