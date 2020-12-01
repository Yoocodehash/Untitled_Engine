#include "Physics.h"
#include "../Rendering/2D/GameObject.h"

#define Gravity glm::vec2(0.0f, -50.0f)

Physics::Physics() : velocity(glm::vec2(0)), acceleration(glm::vec2(0)), parent(nullptr), isStatic(false), angularAcceleration(0),
angularVelocity(0), isRigid(false), gravity(0) 
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

	parent->Translate((velocity + gravity) * deltaTime + (0.5f * acceleration * std::powf(deltaTime, 2)));
	

	//Zero it to require constant force
	velocity = glm::vec2(0);
}

void Physics::SetVelocity(glm::vec2 vel_)
{
	velocity = glm::mat2(glm::cos(glm::radians(parent->GetRotation())), -glm::sin(glm::radians(parent->GetRotation())),
						 glm::sin(glm::radians(parent->GetRotation())), glm::cos(glm::radians(parent->GetRotation()))) * vel_;

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

void Physics::ApplyGravity(bool state_)
{
	if (state_) {
		gravity = Gravity;
	}
	else {
		gravity = glm::vec2(0);
	}
}

void Physics::SetRigidBody(bool state)
{
	isRigid = state;
}

bool Physics::GetRigid() const
{
	return isRigid;
}

void Physics::ApplyForce(glm::vec2 force_)
{
}
