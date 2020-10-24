#include "AI.h"

AI::AI() : Component() {
	
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


