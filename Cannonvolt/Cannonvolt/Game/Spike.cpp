#include "Spike.h"
#include "../Engine/Graphics/ShaderHandler.h"
#include "Character.h"

Spike::Spike() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"), "Blue", this))
{

}

Spike::~Spike()
{

}

bool Spike::OnCreate(glm::vec2 pos_)
{
	SetPosition(pos_);

	SetStatic(true);

	return false;
}

void Spike::Update(const float deltaTime_)
{

}

void Spike::CollisionResponse(GameObject* obj)
{
	if (obj->GetTag() == "Mario") {
		dynamic_cast<Character*>(obj)->Kill();
	}
}
