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

	template<typename T>
	inline void AddComponent()
	{
		T* comp = new T();

		//First check to see if it is a child of component
		Component* item = dynamic_cast<Component*>(comp);
		if (item == nullptr) {
			// Cast failed
			Debug::Error("Not child of Component class", "GameObject.h", __LINE__);
			delete item;
			item = nullptr;
			comp = nullptr;
			return;
		}

		//Next check to see if there is any other component of the same type
		if (GetComponent<T>() != nullptr) {
			Debug::Error("Component of this type is already included", "GameObject.h", __LINE__);
			delete item;
			item = nullptr;
			comp = nullptr;
			return;
		}

		item->OnCreate(this);
		components.push_back(item);
	}

	template<typename T>
	inline T* GetComponent()
	{
		//Loop to find the component
		for (int i = 0; i < components.size(); i++)
		{
			if (T* ptr = dynamic_cast<T*>(components[i])) {
				return ptr;
			}
		}
		Debug::Error("Component does not exist", "GameObject.h", __LINE__);
		return nullptr;
	}

	template<typename T>
	inline void RemoveComponent() {

		for (int i = 0; i < components.size(); i++)
		{
			if (dynamic_cast<T*>(components[i])) {
				delete components[i];
				components[i] = nullptr;
				components.erase(components.begin() + i);
			}
		}
	}


private:
	Sprite* sprite;
	int spriteInstance;

	glm::vec3 position;
	float rotation;
	glm::vec3 scale;
	BoundingBox box;

	std::string tag;

	bool hit;

	std::vector<Component*> components;

};
#endif // !GAMEOBJECT_H
