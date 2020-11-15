#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <sstream>
#include "../../Camera/Camera.h"
#include "Sprite.h"
#include "../../Math/AI.h"
#include "../../Math/Physics.h"


class GameObject
{
public:
	GameObject(Sprite* sprite, glm::vec2 position_ = glm::vec2());
	~GameObject();
	virtual void Update(const float deltaTime_);
	void Draw(Camera* camera_);

	glm::vec2 GetPosition() const;
	float GetRotation() const;
	glm::vec2 GetScale() const;
	BoundingBox GetBoundingBox() const;
	std::string GetTag() const;
	bool GetHit() const;
	Sprite* GetSprite() const;

	void SetPosition(glm::vec2 position_);
	void SetRotation(float rotation_);
	void SetScale(glm::vec2 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);

	void Translate(glm::vec2 trans_); // Move object by the parameter

	virtual void CollisionResponse(GameObject* obj);

	//Physics Functions

	void ApplyVelocity(glm::vec2 force_);

	bool IsStatic() const;

	void SetStatic(bool static_);

	void Flip(bool invert_);

private:
	Sprite* sprite;

	glm::vec2 position;
	float rotation;
	glm::vec2 scale;
	BoundingBox box;

	std::string tag;

	bool hit;

	Physics physics;
};
#endif // !GAMEOBJECT_H
