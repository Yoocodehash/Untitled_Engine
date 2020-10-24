#ifndef KEYEVENTLISTENER_H
#define KEYEVENTLISTINER_H

#include <SDL.h>
#include <glm/glm.hpp>
#include <iostream>
#include <map>


class KeyEventListener {
public:
	static void Press(const SDL_Keycode e_);
	static void Release(const SDL_Keycode e_);

	static std::map<SDL_Keycode, bool> keyMap;

};

#endif