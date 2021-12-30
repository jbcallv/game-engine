#include "SoundHandler.hpp"

SoundHandler::SoundHandler(std::string audioFilePath) {
	if (!buffer.loadFromFile(audioFilePath)) {
		std::cout << "Failed to load audio file. Check path and try again." << std::endl;
	}
	
	sound.setBuffer(buffer);
}

void SoundHandler::Play() {
	sound.play();
}
