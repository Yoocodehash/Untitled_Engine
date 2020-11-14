#include "Character.h"
#include "../Engine/Graphics/ShaderHandler.h"

Character::Character() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"),"Mario", this)) {

}

Character::~Character()
{

}

bool Character::OnCreate()
{
	return true;
}

void Character::Update(const float deltaTime_)
{
	GameObject::Update(deltaTime_);
}

void Character::CollisionResponse(GameObject* obj)
{

	if ( GetBoundingBox().CollisionDepth(&obj->GetBoundingBox()).y < 0)
	
	{
		obj.tag;
	}

	GameObject::CollisionResponse(obj);
}
