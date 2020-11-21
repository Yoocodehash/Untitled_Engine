#pragma once

#include "Modular_Base.h"

class Platformer : public Modular_Base {
public: 
	Platformer();
	virtual ~Platformer();

	virtual bool Initilize() override;
	virtual void Update(const float deltaTime_) override;

	bool a;

};
