#include "GameObject.h"

//TODO: add in load sprite/sheet into gameobject instead of model
GameObject::GameObject(Sprite* sprite, glm::vec2 position_)
{
	position = position_;
	angle = 0.0f;
	rotation = glm::vec2(0.0f, 1.0f);
	scale = glm::vec2(1.0f);
	tag = "";
	hit = false;
	
	if (sprite) {
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

glm::vec2 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetAngle() const
{
	return angle;
}

glm::vec2 GameObject::GetRotation() const
{
	return rotation;
}

glm::vec2 GameObject::GetScale() const
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
	position = position_;
	if (sprite) {
		sprite->UpdateInstance(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetAngle(float angle_)
{
	angle = angle_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetRotation(glm::vec2 rotation_)
{
	rotation = rotation_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
	}
}

void GameObject::SetScale(glm::vec2 scale_)
{
	scale = scale_;
	if (model) {
		model->UpdateInstance(modelInstance, position, angle, rotation, scale);
		box.transform = model->GetTransform(modelInstance);
		box.minVert *= scale.x > 1.0f ? scale : (scale / 2.0f);
		box.maxVert *= scale.x > 1.0f ? scale : (scale / 2.0f);
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
