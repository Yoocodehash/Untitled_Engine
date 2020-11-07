#include "Physics.h"
#include "../Rendering/2D/GameObject.h"


Physics::Physics() : velocity(glm::vec2(0)), acceleration(glm::vec2(0)), parent(nullptr), isStatic(false) {

}

Physics::~Physics() {
	parent = nullptr;
}

void Physics::OnCreate(GameObject* parent_) {
	parent = parent_;
}

void Physics::Update(const float deltaTime)
{
	parent->Translate(velocity * deltaTime + (0.5f * acceleration * std::powf(deltaTime, 2)));

	velocity += acceleration * deltaTime;
}

void Physics::SetVelocity(glm::vec2 vel_)
{
	velocity = vel_;
}

void Physics::RigidbodyCollision(GameObject* obj)
{
	glm::vec2 depth = parent->GetBoundingBox().CollisionDepth(&obj->GetBoundingBox());

	parent->Translate(depth);
}

void Physics::SetStatic(bool static_)
{
	isStatic = static_;
}

bool Physics::GetStatic() const
{
	return isStatic;
}
