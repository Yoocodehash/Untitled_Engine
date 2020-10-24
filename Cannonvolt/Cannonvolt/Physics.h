#pragma once

class GameObject;

Physics physics;

OnCreate(GameObject* parent_);


physics.update(deltaTime_);













class GameObject;

Physics(GameObject* obj_);

private:

    GameObject* parent;

    Physics physics;

    OnCreate(GameObject* parent_);