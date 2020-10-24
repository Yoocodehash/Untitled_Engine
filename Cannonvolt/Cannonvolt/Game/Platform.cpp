#include "Platform.h"

Platform::Platform() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Mario"))
{
}

Platform::~Platform()
{
}

bool Platform::OnCreate()
{
	return true;
}

void Platform::Update(const float deltaTime_)
{
}
