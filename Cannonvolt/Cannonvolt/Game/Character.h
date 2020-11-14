#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Engine/Rendering/2D/GameObject.h"
#include "FireBall.h"

class Character : public GameObject {
public:
	Character();
	virtual ~Character();

	virtual bool OnCreate();
	virtual void Update(const float deltaTime_) override;

	void Shot();

private:
	FireBall fire;

};


#endif // !Character_h

/* I think the function i need in Key thing is Apply is called ApplyVelocity */
