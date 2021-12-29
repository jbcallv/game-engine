#include "MusicHandler.hpp"

MusicHandler::MusicHandler(std::string audioFilePath, bool loop) {
	if (!music.openFromFile(audioFilePath)) {
		std::cout << "Failed to load audio file. Check path and try again." << std::endl;
	}

	music.setLoop(loop);
}

void MusicHandler::Play() {
	music.play();
	//music.setLoop(true);
}
