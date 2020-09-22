#include "GameObject.h"

//TODO: add in load sprite/sheet into gameobject instead of model
GameObject::GameObject(Sprite* sprite_, glm::vec2 position_)
{
	sprite = sprite_;
	position = glm::vec3(position_,0);
	rotation = 0;
	scale = glm::vec3(1.0f,1.0,0);
	tag = "";
	hit = false;

	if (sprite) {
		//sprite = sprite_;
		box = sprite->GetBoundingBox();
		box.transform = sprite->GetTransform();
	}
}

GameObject::~GameObject()
{
	
}

void GameObject::Render(Camera* camera_)
{
	if (sprite) {
		sprite->Render(camera_);
	}
}

glm::vec3 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetRotation() const
{
	return rotation;
}

glm::vec3 GameObject::GetScale() const
{
	return scale;
}

BoundingBox GameObject::GetBoundingBox() const
{
	return box;
}

std::string GameObject::GetTag() const
{
	return tag;
}

bool GameObject::GetHit() const
{
	return hit;
}

//TODO: do this after the question
void GameObject::SetPosition(glm::vec2 position_)
{
	position = glm::vec3(position_,0.0f);
	if (sprite) {
		sprite->SetPosition(position_);
		box.transform = sprite->GetTransform();
	}
}

void GameObject::SetRotation(float rotation_)
{
	rotation = rotation_;
	if (sprite) {
		sprite->SetRotation(rotation_);
		box.transform = sprite->GetTransform();
	}
}

void GameObject::SetScale(glm::vec2 scale_)
{
	scale = glm::vec3(scale_,0.0f);
	if (sprite) {
		sprite->SetScale(scale_);
		box.transform = sprite->GetTransform();
		//TODO: Fix scaleing
		//box.width *= scale.x > 1.0f ? scale : (scale / 2.0f);
		//box.height *= scale.y > 1.0f ? scale : (scale / 2.0f);
	}
}

void GameObject::SetTag(std::string tag_)
{
	tag = tag_;
}

void GameObject::SetHit(bool hit_, int buttonType_)
{
	hit = hit_;
	if (hit) {
		std::cout << tag << " was hit" << std::endl;
	}
}
