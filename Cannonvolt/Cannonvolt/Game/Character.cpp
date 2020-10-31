#include "Character.h"

Character::Character() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"),"Mario")) {

}

Character::~Character()
{

}

bool Character::OnCreate()
{
	physics.OnCreate(this);

	return true;
}

void Character::Update(const float deltaTime_)
{
	physics.Update(deltaTime_);
}
