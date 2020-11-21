#include "Character.h"
#include "../Engine/Graphics/ShaderHandler.h"
#include "../Engine/Rendering/SceneGraph.h"
#include "FireBall.h"

std::map<std::string, bool> Character::modules = std::map<std::string, bool>();

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

bool Character::IsDead()
{
	return dead;
}

void Character::Kill()
{
	dead = true;
}

void Character::LoadMods()
{
	modules["Movement"] = false;
}

bool Character::GetMod(std::string name_)
{
	return modules[name_];
}

void Character::SetMod(std::string name_, bool state_)
{
	modules[name_] = state_;
}

void Character::Shot()
{
	SceneGraph::GetInstance()->AddGameObject(&FireBall(GetPosition(), GetRotation()));
}

void Character::CollisionResponse(GameObject* obj)
{

	if ( GetBoundingBox().CollisionDepth(&obj->GetBoundingBox()).y < 0)
	{
		SceneGraph::GetInstance()->RemoveGameObject(obj->GetTag());

		return;

	}
	GameObject::CollisionResponse(obj);
}
