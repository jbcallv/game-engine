#include "MusicHandler.hpp"
#include <string>
#include <iostream>
#include <SFML/Audio.hpp>

MusicHandler::MusicHandler() {

}

MusicHandler::MusicHandler(std::string audioFilePath, bool loop) {
	if (!music.openFromFile(audioFilePath)) {
		std::cout << "Failed to load audio file. Check path and try again." << std::endl;
	}

	music.setLoop(loop);
}

void MusicHandler::load(const std::string& audioFilePath) {
	if (!music.openFromFile(audioFilePath)) {
		std::cout << "Failed to load audio file. Check path and try again." << std::endl;
	}
}

void MusicHandler::Play() {
	music.setLoop(true);
	music.play();
}

void MusicHandler::Stop() {
	music.stop();
}
