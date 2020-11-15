#ifndef FIREBALL_H
#define FIREBALL_H
#include "../Engine/Rendering/2D/GameObject.h"

class FireBall : public GameObject {
public:
	FireBall();
	 ~FireBall();

	 bool OnCreate(glm::vec2 position_, float angle_);
	 void Update(const float deltaTime_) override;

};
#endif // !FireBall_h




/* #pragma once
class FireBall
{
}; */
