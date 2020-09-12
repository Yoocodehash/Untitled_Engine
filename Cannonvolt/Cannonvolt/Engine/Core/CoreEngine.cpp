#include "CoreEngine.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;


CoreEngine::CoreEngine() : isRunning(false) {

}

CoreEngine::~CoreEngine() {

}

void CoreEngine::OnDestroy()
{
	SDL_Quit();
	exit(0);
}

void CoreEngine::Update(const float deltaTime_)
{
}

void CoreEngine::Render()
{
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_)
{
	return isRunning = true;
}

void CoreEngine::Run()
{
	while (isRunning) {

		Update(timer.GetDeltaTime());

		Render();

	}

	if (!isRunning) {
		OnDestroy();
	}
}

bool CoreEngine::GetIsRunning() const
{
	return isRunning;
}

CoreEngine* CoreEngine::GetInstance()
{
	if (engineInstance.get() == nullptr) {
		engineInstance.reset(new CoreEngine);
	}
	return engineInstance.get();
}

void CoreEngine::Exit()
{
	isRunning = false;
}
