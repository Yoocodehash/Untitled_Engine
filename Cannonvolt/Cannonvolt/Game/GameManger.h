#pragma once
#include "Character.h"

class GameManager {
public:

	GameManager();
	~GameManager();

	bool OnCreate(Character* player_);

	void Update();


private:

	Character* playerPtr;
};