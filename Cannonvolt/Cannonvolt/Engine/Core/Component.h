#pragma once

class GameObject;

class Component {

public:
	Component() : parent(nullptr) { }

	virtual ~Component() {
		parent = nullptr;
	}

	virtual bool OnCreate(GameObject* parent_) = 0;
	virtual void Update(const float deltaTime_) = 0;

protected:
	GameObject* parent;
};