#include "GameObject.h"

GameObject::GameObject(Sprite* sprite_, glm::vec2 position_)
{
	sprite = sprite_;
	position = position_;
	rotation = 0;
	scale = glm::vec2(1.0f,1.0);
	tag = "";
	hit = false;

	if (sprite) {
		spriteInstance = sprite->CreateInstance(position, rotation, scale);
		box = sprite->GetBoundingBox();
		box.pos = position;
	}
}

GameObject::~GameObject()
{
	
}


void GameObject::Draw(Camera* camera_)
{
	if (sprite) {
		sprite->Draw(camera_);
	}
}

glm::vec2 GameObject::GetPosition() const
{
	return position;
}

float GameObject::GetRotation() const
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
		sprite->UpdateInstance(spriteInstance, position,rotation,scale);
		box.pos = position_;
	}
}

void GameObject::SetRotation(float rotation_)
{
	rotation = rotation_;
	if (sprite) {
		sprite->UpdateInstance(spriteInstance, position, rotation, scale);
	}
}

void GameObject::SetScale(glm::vec2 scale_)
{
	scale = scale_;
	if (sprite) {
		sprite->UpdateInstance(spriteInstance, position, rotation, scale);
		box.dimentions = scale_ * sprite->GetDimentions();
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

void GameObject::Translate(glm::vec2 trans_)
{
	SetPosition(position + trans_);
}

//TODO: finish the response peter
void GameObject::CollisionResponse()
{
}
