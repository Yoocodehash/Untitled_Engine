#include "KeyEventListener.h"
#include <iostream>

bool KeyEventListener::right = false;

void KeyEventListener::Update(SDL_Event e_){

	std::printf("pressed button ->");

	switch (e_.key.keysym.sym) {
		
	case SDLK_w:
	case SDLK_UP:
		std::cout << " w / UP pressed" << std::endl;
		//temp
		break;
	case SDLK_d:
	case SDLK_RIGHT:
		std::cout << " d / RIGHT pressed" << std::endl;
		//temp
		break;
	case SDLK_s:
	case SDLK_DOWN:
		std::cout << " s / DOWN pressed" << std::endl;
		//temp
		break;
	case SDLK_a:
	case SDLK_LEFT:
		std::cout << " a / LEFT pressed" << std::endl;
		//temp
		break;
	default:
		break;
		
	}
}

