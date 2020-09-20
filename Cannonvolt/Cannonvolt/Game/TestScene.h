#pragma once
#include "../Engine/Core/Scene.h"
class TestScene : public Scene 
{
public:
	TestScene();
	~TestScene();

	virtual bool OnCreate() override;
	virtual void Update(const float deltaTime_) override;
	virtual void Render() override;
};

