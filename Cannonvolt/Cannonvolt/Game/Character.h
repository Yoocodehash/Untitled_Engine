#ifndef CHARACTER_H
#define CHARACTER_H
#include "../Engine/Rendering/2D/GameObject.h"
#include <map>

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

	static void LoadMods();

	static bool GetMod(std::string name_);

	static void SetMod(std::string name_, bool state_);
private:

	static std::map<std::string, bool> modules;
	bool dead;
};

#endif // !Character_h
