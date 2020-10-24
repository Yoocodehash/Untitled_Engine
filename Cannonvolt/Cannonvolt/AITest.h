#pragma once
#include "Engine/Math/AI.h"

class AITest : Behavior
{
public:
	AITest();
	~AITest();

	void OnStart();
	STATUS Update() override;
	void OnEnd();
};

