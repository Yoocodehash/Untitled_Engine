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
	virtual void CollisionResponse(GameObject* obj) override;
};

#endif // !Character_h
