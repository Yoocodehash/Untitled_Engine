#pragma once

#include "../Engine/Rendering/2D/GameObject.h"

class Spike : public GameObject {
public:
	Spike();
	~Spike();


	bool OnCreate(glm::vec2 pos_);
	virtual void Update(const float deltaTime_);
	virtual void CollisionResponse(GameObject* obj);
};