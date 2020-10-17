#include "KeyEventListener.h"

std::map<SDL_Keycode, bool> KeyEventListener::keyMap = std::map<SDL_Keycode, bool>();

void KeyEventListener::Press(const SDL_Keycode e_){

	std::printf("pressed button ->");
	
	keyMap[e_] = true;
	std::cout << e_ << std::endl;

	if (keyMap[SDLK_a] == true) {
		std::cout << "Pressing!" << std::endl;		
	}

}

void KeyEventListener::Release(SDL_Keycode e_){

	std::printf("released button ->");

	keyMap[e_] = false;
	std::cout << e_ << std::endl;

	if (keyMap[SDLK_a] == false) {
		std::cout << "Released!" << std::endl;
	}

}


