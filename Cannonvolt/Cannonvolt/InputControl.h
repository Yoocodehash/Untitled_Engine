#ifndef INPUTCONTROL_H
#define INPUTCONTROL_H
#include "Game/Character.h"
//#include "Engine/Events/KeyEventListener.h"

class InputControl {
	
public:
	InputControl();
	~InputControl();
	void Init(GameObject* player_);
	void Update(float deltaTime_);
private:
	GameObject* player;


};

#endif
