#include "AI.h"
#include "../Rendering/2D/GameObject.h"

AI::AI() {
	
}

AI::~AI()
{
}

bool AI::OnCreate(GameObject* parent_)
{
	parent = parent_;
	root = new Selector();
	return true;
}

void AI::Update(const float deltaTime_)
{
}

void AI::AddBehavior(Behavior* node_)
{

}


