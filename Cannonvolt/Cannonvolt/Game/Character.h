#pragma once
#include "../Engine/Rendering/2D/GameObject.h"

class Character : public GameObject {
public:
	Character();
	~Character();

	bool OnCreate();
	void Update(const float deltaTime_) override;

};