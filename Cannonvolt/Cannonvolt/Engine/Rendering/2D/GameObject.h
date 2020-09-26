#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <sstream>
#include "../../Camera/Camera.h"
#include "Sprite.h"


class GameObject
{
public:
	GameObject(Sprite* sprite, glm::vec2 position_ = glm::vec2());
	~GameObject();
	void Render(Camera* camera_);
	virtual void Update(const float deltaTime_) = 0;
	
	glm::vec3 GetPosition() const;
	float GetRotation() const;
	glm::vec3 GetScale() const;
	BoundingBox GetBoundingBox() const;
	std::string GetTag() const;
	bool GetHit() const;

	void SetPosition(glm::vec2 position_);
	void SetRotation(float rotation_);
	void SetScale(glm::vec2 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);


private:
	Sprite* sprite;
	int spriteInstance;

	glm::vec3 position;
	float rotation;
	glm::vec3 scale;
	BoundingBox box;

	std::string tag;

	bool hit;

};
#endif // !GAMEOBJECT_H
