#include "Physics.h"
#include "../Rendering/2D/GameObject.h"


Physics::Physics() : velocity(glm::vec2(0)), acceleration(glm::vec2(0)), parent(nullptr), isStatic(false), angularAcceleration(0),
angularVelocity(0)
{

}

Physics::~Physics() {
	parent = nullptr;
}

void Physics::OnCreate(GameObject* parent_) {
	parent = parent_;
}

void Physics::Update(const float deltaTime)
{
	//parent->SetRotation(angularVelocity * deltaTime + 0.5f * angularAcceleration * pow(deltaTime, 2));

	//Step 3. angle velocity
	//angularVelocity += angularAcceleration * deltaTime;

	parent->Translate(velocity * deltaTime + (0.5f * acceleration * std::powf(deltaTime, 2)));


	//Zero it to require constant force
	velocity = glm::vec2(0);
}

void Physics::SetVelocity(glm::vec2 vel_)
{
	
	velocity = glm::mat2(cos(glm::radians(parent->GetRotation())), -sin(glm::radians(parent->GetRotation())), sin(glm::radians(parent->GetRotation())), cos(glm::radians(parent->GetRotation()))) * vel_;
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

void Physics::Gravity(const float deltaTime)
{
	velocity += glm::vec2(0.0f, -8) * deltaTime;
}

void Physics::ApplyForce(glm::vec2 force_)
{
}
