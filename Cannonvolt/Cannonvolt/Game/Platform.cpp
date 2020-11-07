#include "Platform.h"
#include "../Engine/Graphics/ShaderHandler.h"

Platform::Platform() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Mario", this))
{
}

Platform::~Platform()
{
}

bool Platform::OnCreate()
{
	SetStatic(true);
	return true;
}

void Platform::Update(const float deltaTime_)
{
}
