#include "Character.h"

Character::Character() : GameObject(new Sprite(ShaderHandler::GetInstance()->GetShader("basicShader"),"Mario")) {

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
	int a = 1;
}
