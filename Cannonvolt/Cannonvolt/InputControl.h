#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include "Game/Character.h"
//#include "Engine/Events/KeyEventListener.h"

class InputControl {
	
public:
	InputControl();
	~InputControl();
	void Init(Character* player_);
	void Update(float deltaTime_);
	
private:
	Character* player;


};

#endif
