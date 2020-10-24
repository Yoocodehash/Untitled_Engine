#pragma once
#include "..\Core\Component.h"
#include <glm/glm.hpp>
#include <vector>

enum class STATUS {
	INVALID,
	SUCCESS,
	RUNNING,
	FAILURE
};

class Behavior {
protected:
	virtual void OnStart() = 0;
	virtual STATUS Update() = 0;
	virtual void OnEnd(STATUS status_) = 0;

private:
	STATUS status;

public:
	Behavior() : status(STATUS::INVALID) {}
	virtual ~Behavior() {}
	STATUS Tick() {
		if (status != STATUS::RUNNING) OnStart();
		status = Update();
		if (status != STATUS::RUNNING) OnEnd(status);
		return status;
	}
};

class Composite : public Behavior {
public:
	void AddChild(Behavior* behavior_) { children.emplace_back(behavior_); }
	void RemoveChild(Behavior* behavior_) { 
		for (size_t i = 0; i < children.size(); i++)
		{
			/*
			TODO: question?
			goal is to remove the behavior in the vector that matches the passed element
			compare the element to the elements in the vector
			if they match remove the element and continue

			issue:

			how to compare them?
			comapre the type of element in the child with the vector
			problem: can you even get the type of element inside the vector as vectors only hold the base class

			dynamic cast
			does not work as that would again require the derived class to compare too in order to check

			additional note:
			as it is being passed as a Behavior pointer and not the behavir type i dont know if you could get back the derived 
			type to comapre to?
			*/
			//if (dynamic_cast<>(children[i])) {
			//	delete components[i];
		//		components[i] = nullptr;
		//		components.erase(components.begin() + i);
		//		return;
		//	}
		}
	}
	void ClearChildren() {

	}
	
public:
	typedef std::vector<Behavior*> Behaviors;
	Behaviors children;
};

class Sequence : public Composite {
protected:
	Behaviors::iterator currentChild;
	virtual void OnStart() override {
		currentChild = children.begin();
	}
	virtual STATUS Update() override {
		//Keep going until a child behavior says it’s running.
		while (true) {
			STATUS s = (*currentChild)->Tick();
			//If child fails or keeps running, do the same.
			if (s != STATUS::SUCCESS) { return s; }
			//Move on until we hit the end of the array!
			if (++currentChild == children.end()) {
				return STATUS::SUCCESS;
			}
		}
		return STATUS::INVALID;//Unexpected loop exit.
	}
	virtual void OnEnd(STATUS status_) override {

	}
};

class Filter : public Sequence {
public:
	void AddCondition(Behavior* condition) {
		//Use insert() if you store children in std::vector
		children.insert(children.begin(),condition);
	}
	void AddAction(Behavior* action) {
		children.push_back(action);
	}
};

class Selector : public Composite {
	Behaviors::iterator currentChild;
	virtual void OnStart() override {
		currentChild = children.begin();
	}

	virtual STATUS Update() {
		//Keep going until a child behavior says it’s running.
		while (true) {
			STATUS s = (*currentChild)->Tick();
			//If child succeeds or keeps running, do the same.
			if (s != STATUS::FAILURE) return s;
			//Continue search for fallback until the last child.
			if (++currentChild == children.end())
				return STATUS::FAILURE;
		}
		return STATUS::INVALID;//”Unexpected loop exit.”
	}
	virtual void OnEnd(STATUS status_) {

	}
};

class AI : public Component {
public:
	AI();
	~AI();

	bool OnCreate(GameObject* parent_) override;
	void Update(const float deltaTime_) override;

	void AddBehavior(Behavior* node_);

private:
	Behavior* root;
};