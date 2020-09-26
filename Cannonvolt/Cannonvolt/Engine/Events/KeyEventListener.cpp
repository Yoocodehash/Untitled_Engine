#include "KeyEventListener.h"
#include <iostream>



void KeyEventListener::Update(SDL_Event e_){

	std::printf("pressed");
	std::printf("pressed" + e_.type);
}

