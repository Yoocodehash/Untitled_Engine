#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Engine/Rendering/2D/GameObject.h"

class Character : public GameObject {
public:
	Character();
	virtual ~Character();

	bool OnCreate();
	virtual void Update(const float deltaTime_) override;

	virtual void CollisionResponse(GameObject* obj) override;

	void Shot();

	//Death functions
	bool IsDead();

	void Kill();
private:
	bool dead;
};

#endif // !Character_h
