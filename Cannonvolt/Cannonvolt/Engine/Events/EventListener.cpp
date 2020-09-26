#include "EventListener.h"
#include "../Core/CoreEngine.h"

EventListener::~EventListener()
{
}

void EventListener::Update()
{
	SDL_Event sdlEvent;
	while (SDL_PollEvent(&sdlEvent)) {
		if (sdlEvent.type == SDL_QUIT) {
			CoreEngine::GetInstance()->Exit();
		}

		//else if (sdlEvent.type == SDL_KEYDOWN) {
			
		//}
				
		switch (sdlEvent.type) {
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_KEYDOWN:
			KeyEventListener::Update(sdlEvent);
			break;
		default:
			break;
		}
	}
}
