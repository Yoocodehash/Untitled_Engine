#include "FireBall.h"
#include "../Engine/Graphics/ShaderHandler.h"

FireBall::FireBall(glm::vec2 position_, float angle_) : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Mario", this)) {

	SetPosition(position_);
	SetRotation(angle_);
	ApplyVelocity(glm::vec2(1.0f, 0.0f));
}

FireBall::~FireBall()
{

}

void FireBall::Update(const float deltaTime_)
{
	GameObject::Update( deltaTime_);
}

void FireBall::CollisionResponse(GameObject* obj)
{
}

