#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "Model.h"

class GameObject
{
public:
	GameObject(Model* model_, glm::vec2 position_ = glm::vec2());
	~GameObject();
	void Render(Camera* camera_);
	virtual void Update(const float deltaTime_) = 0;
	
	glm::vec3 GetPosition() const;
	float GetAngle() const;
	glm::vec2 GetRotation() const;
	glm::vec2 GetScale() const;
	BoundingBox GetBoundingBox() const;
	std::string GetTag() const;
	bool GetHit() const;

	void SetPosition(glm::vec2 position_);
	void SetAngle(float angle_);
	void SetRotation(glm::vec2 rotation_);
	void SetScale(glm::vec2 scale_);
	void SetTag(std::string tag_);
	void SetHit(bool hit_, int buttonType_);


private:
	Model* model;
	int modelInstance;

	glm::vec2 position;
	float angle;
	glm::vec2 rotation;
	glm::vec2 scale;
	BoundingBox box;

	std::string tag;

	bool hit;

};
#endif // !GAMEOBJECT_H
