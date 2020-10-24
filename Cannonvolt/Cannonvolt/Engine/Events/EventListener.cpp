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

				
		switch (sdlEvent.type) {
		case SDL_MOUSEBUTTONDOWN:
		case SDL_MOUSEBUTTONUP:
		case SDL_MOUSEMOTION:
		case SDL_MOUSEWHEEL:
			MouseEventListener::Update(sdlEvent);
			break;
		case SDL_KEYDOWN:
			KeyEventListener::Press(sdlEvent.key.keysym.sym);
			break;
		case SDL_KEYUP:
			KeyEventListener::Release(sdlEvent.key.keysym.sym);
			break;
		default:
			break;
		}
	}
}
