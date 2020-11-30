#pragma once
#include <glm/glm.hpp>

class GameObject;

class Physics {
public:
	Physics();
	~Physics();

	void OnCreate(GameObject* parent_);

	void Update(const float deltaTime);

	//Setters

	void SetVelocity(glm::vec2 vel_);

	void RigidbodyCollision(GameObject* obj);

	void SetStatic(bool static_);

	bool GetStatic() const;

	void ApplyGravity(bool state);

	void SetRigidBody(bool state);
	bool GetRigid() const;

	void ApplyForce(glm::vec2 force_);

private:
	GameObject* parent;

	glm::vec2 velocity, acceleration;

	float angularVelocity, angularAcceleration;

	bool isStatic;
	bool isRigid;
	
	glm::vec2 gravity;

};