#pragma once

#include "Modular_Base.h"

class Platformer : public Modular_Base {
public: 
	Platformer();
	~Platformer();

	virtual bool Initilize() override;
	virtual void Update(const float deltaTime_) override;

};
