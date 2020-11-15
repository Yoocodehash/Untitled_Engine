#include "FireBall.h"
#include "../Engine/Graphics/ShaderHandler.h"
#include "Engine/Rendering/2D/GameObject.h"
#include "Engine/Graphics/ShaderHandler.cpp"

FireBall::FireBall() : FireBall(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Mario", this)) {

}

FireBall::~FireBall()
{

}

bool FireBall::OnCreate()
{
	return true;
}

void FireBall::Update(const float deltaTime_)
{
	FireBall::Update( deltaTime_);
}
