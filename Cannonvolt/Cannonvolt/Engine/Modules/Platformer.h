#pragma once

#include "Modular_Base.h"

class Platformer : public Modular_Base {
public: 
	Platformer();
	~Platformer();

	virtual bool Initilize();
	virtual void Update(const float deltaTime_);

};
