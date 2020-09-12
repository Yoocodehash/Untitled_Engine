#ifndef COREENGINE_H
#define COREENGINE_H

#include <memory>

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

	void Exit();

private:
	CoreEngine();
	~CoreEngine();

	static std::unique_ptr<CoreEngine> engineInstance;
	friend std::default_delete<CoreEngine>;

	void OnDestroy();
	void Update(const float deltaTime_);
	void Render();

	bool isRunning;
};

#endif // ! COREENGINE_H