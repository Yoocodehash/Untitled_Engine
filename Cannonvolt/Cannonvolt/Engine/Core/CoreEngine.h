#ifndef COREENGINE_H
#define COREENGINE_H

#include <memory>
#include <glm/vec2.hpp>
#include "Window.h"
#include "Timer.h"
#include "Debug.h"
#include "GameInterface.h"
#include "Scene.h"


class CoreEngine
{
public:
	CoreEngine(const CoreEngine&) = delete;
	CoreEngine(CoreEngine&&) = delete;
	CoreEngine& operator =(const CoreEngine&) = delete;
	CoreEngine& operator =(CoreEngine&&) = delete;

	bool OnCreate(std::string name_, int width_, int height_);
	void Run();
	bool GetIsRunning() const;


	static CoreEngine* GetInstance();
	int GetCurrentScene();
	glm::vec2 GetWindowSize() const;

	void SetGameInterface(GameInterface* gameInterface);

	//Set current scene
	void SetCurrentScene(int sceneNum_);
	
	//Stop engine
	void Exit();

private:
	CoreEngine();
	~CoreEngine();

	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;

	void OnDestroy();
	void Update(const float deltaTime_);
	void Render();

	Window* window;
	bool isRunning;

	Timer timer;
	unsigned int fps;

	GameInterface* gameInterface;

	int currentSceneNum;
};

#endif // ! COREENGINE_H
