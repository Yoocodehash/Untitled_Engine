#pragma once

#include "../Engine/Rendering/2D/GameObject.h"

class Platform : public GameObject {

public:
	Platform();
	~Platform();

	bool OnCreate();
	void Update(const float deltaTime_);


};