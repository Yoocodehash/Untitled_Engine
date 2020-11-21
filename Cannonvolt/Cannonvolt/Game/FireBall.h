#ifndef FIREBALL_H
#define FIREBALL_H
#include "../Engine/Rendering/2D/GameObject.h"

class FireBall : public GameObject {
public:
	FireBall(glm::vec2 position_, float angle_);
	 ~FireBall();

	 void Update(const float deltaTime_) override;

	 virtual void CollisionResponse(GameObject* obj) override;

};
#endif // !FireBall_h