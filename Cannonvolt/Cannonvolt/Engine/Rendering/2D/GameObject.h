#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <sstream>
#include "../../Camera/Camera.h"
#include "Sprite.h"
#include "../../Math/AI.h"


class GameObject
{
public:
	GameObject(Sprite* sprite, glm::vec2 position_ = glm::vec2());
	~GameObject();
	virtual void Update(const float deltaTime_) = 0;
	void Draw(Camera* camera_);

	
	glm::vec2 GetPosition() const;
	float GetRotation() const;
	glm::vec2 GetScale() const;
	BoundingBox GetBoundingBox() const;
	std::string GetTag() const;
	bool GetHit() const;

	void SetPosition(glm::vec2 position_);
	void SetRotation(float rotation_);
	void SetScale(glm::vec2 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);

	void Translate(glm::vec2 trans_); // Move object by the parameter

private:
	Sprite* sprite;
	int spriteInstance;

	glm::vec2 position;
	float rotation;
	glm::vec2 scale;
	BoundingBox box;

	std::string tag;

	bool hit;

};
#endif // !GAMEOBJECT_H
