#include "KeyEventListener.h"
#include <iostream>



void KeyEventListener::Update(SDL_Event e_){

	std::cout << "pressed ", e_ << std::endl;

}

