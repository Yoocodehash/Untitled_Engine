#include "CoreEngine.h"
#include "Window.h"
#include "Debug.h"
#include "Scene.h"
#include "../../Game/Character.h"

std::unique_ptr<CoreEngine> CoreEngine::engineInstance = nullptr;

CoreEngine::CoreEngine() : window(nullptr), isRunning(false), fps(120), gameInterface(nullptr), currentSceneNum(0), camera(nullptr) {
	
}

CoreEngine::~CoreEngine()
{
	OnDestroy();
}

bool CoreEngine::OnCreate(std::string name_, int width_, int height_, std::vector<Modular_Base> mods)
{
	Debug::DebugInit("Debug Log");
	Debug::SetSeverity(MessageType::TYPE_INFO);

	window = new Window();
	if (!window->OnCreate(name_, width_, height_)) {
		Debug::FatalError("Window failed to initialize", "CoreEngine", __LINE__);
		return isRunning = false;
	}

	SDL_WarpMouseInWindow(window->GetWindow(), window->GetWidth() / 2, window->GetHeight() / 2);

	ShaderHandler::GetInstance()->CreateProgram("basicShader",
		"Engine/Shaders/VertexShader.glsl",
		"Engine/Shaders/FragmentShader.glsl");

	if (gameInterface) {
		if (!gameInterface->OnCreate()) {
			Debug::Error("GameInterface could not be created", "CoreEngine.cpp", __LINE__);
			return isRunning = false;
		}
	}

	timer.Start();

	Debug::Info("Everything was created okay", "CoreEngine.cpp", __LINE__);

	Character::LoadMods();


	for (auto m : mods) {
		m.Initilize();
	}

	return isRunning = true;
}

void CoreEngine::Run()
{
	while (isRunning) {
		timer.UpdateFrameTicks();

		EventListener::Update();

		Update(timer.GetDeltaTime());

		Draw();

		SDL_Delay(timer.GetSleepTime(fps));

	}

	if (!isRunning) {
		OnDestroy();
	}
}

bool CoreEngine::GetIsRunning() const
{
	return isRunning;
}

CoreEngine * CoreEngine::GetInstance()
{
	if(engineInstance.get() == nullptr){
		engineInstance.reset(new CoreEngine);
	}
	return engineInstance.get();
}

void CoreEngine::OnDestroy()
{
	SceneGraph::GetInstance()->OnDestroy();
	ShaderHandler::GetInstance()->OnDestroy();
	TextureHandler::GetInstance()->OnDestroy();

	delete gameInterface;
	gameInterface = nullptr;

	delete window;
	window = nullptr;

	delete camera;
	camera = nullptr;

	SDL_Quit();
	exit(0);
}

void CoreEngine::Update(const float deltaTime_)
{
	if (gameInterface) {
		gameInterface->Update(deltaTime_);
	}
}

void CoreEngine::Draw()
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	//glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if (gameInterface) {
		gameInterface->Draw();
	}
	
	SDL_GL_SwapWindow(window->GetWindow());
}

void CoreEngine::SetGameInterface(GameInterface * gameInterface_)
{
	gameInterface = gameInterface_;
}

glm::vec2 CoreEngine::GetWindowSize() const
{
	return glm::vec2(window->GetWidth(), window->GetHeight());
}

Camera * CoreEngine::GetCamera() const
{
	return camera;
}

int CoreEngine::GetCurrentScene()
{
	return currentSceneNum;
}

void CoreEngine::SetCurrentScene(int sceneNum_)
{
	currentSceneNum = sceneNum_;
}

void CoreEngine::SetCamera(Camera * camera_)
{
	camera = camera_;
}

void CoreEngine::Exit()
{
	isRunning = false;
}



