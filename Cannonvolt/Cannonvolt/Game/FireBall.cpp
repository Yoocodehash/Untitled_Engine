#include "FireBall.h"
#include "../Engine/Graphics/ShaderHandler.h"

FireBall::FireBall() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Mario", this)) {

}

FireBall::~FireBall()
{

}

bool FireBall::OnCreate(glm::vec2 position_, float angle_)
{
	SetPosition (position_);
	SetRotation(angle_);
	ApplyVelocity(glm::vec2 (1.0f, 0.0f));
	return true;
}

void FireBall::Update(const float deltaTime_)
{
	GameObject::Update( deltaTime_);
}

