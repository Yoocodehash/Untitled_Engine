#include "Platformer.h"
#include "../../Game/Character.h"

Platformer::Platformer()
{
}

Platformer::~Platformer()
{
}

bool Platformer::Initilize()
{
	//Here go to all the classes that need it and set to on the functions that need it.
	Character::SetMod("Movement", false);
	Character::SetMod("Flight", true);
	
	return true;
}

void Platformer::Update(const float deltaTime_)
{
}
