#include "Character.h"
#include "../Engine/Graphics/ShaderHandler.h"
#include "../Engine/Rendering/SceneGraph.h"

Character::Character() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"),"Mario", this)) {

}

Character::~Character()
{

}

bool Character::OnCreate()
{
	SetTag("Mario");
	return true;
}

void Character::Update(const float deltaTime_)
{
	GameObject::Update(deltaTime_);
}

void Character::Shot()
{
	fire.OnCreate(GetPosition(), GetRotation());
	SceneGraph::GetInstance()->AddGameObject(&fire);
}

void Character::CollisionResponse(GameObject* obj)
{

	if ( GetBoundingBox().CollisionDepth(&obj->GetBoundingBox()).y < 0)
	{
	}

	GameObject::CollisionResponse(obj);
}
