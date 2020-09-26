#include "CollisionDetection.h"

#include "Ray.h"
#include "../Core/CoreEngine.h"

Ray CollisionDetection::ScreenPosToWorldRay(glm::vec2 mouseCords_, glm::vec2 screenSize_, Camera * camera_)
{
	//NDC Version
	glm::vec4 rayStart_NDC((mouseCords_.x / screenSize_.x - 0.5f) * 2.0f,
		(mouseCords_.y / screenSize_.y - 0.5f) * 2.0f,
		-1.0f,
		1.0f);
	glm::vec4 rayEnd_NDC((mouseCords_.x / screenSize_.x - 0.5f) * 2.0f,
		(mouseCords_.y / screenSize_.y - 0.5f) * 2.0f,
		0.0f,
		1.0f);

	glm::mat4 inverse = glm::inverse(camera_->GetPerspective() * camera_->GetView());

	glm::vec4 rayStart_World = inverse * rayStart_NDC;
	rayStart_World /= rayStart_World.w;

	glm::vec4 rayEnd_World = inverse * rayEnd_NDC;
	rayEnd_World /= rayEnd_World.w;

	glm::vec3 rayDir_World(rayEnd_World - rayStart_World);

	rayDir_World = glm::normalize(rayDir_World);

	return Ray(glm::vec3(rayStart_World), rayDir_World);
}


/*
bool CollisionDetection::RayObbIntersection(Ray * ray_, BoundingBox * box_)
{
	float tMin = CoreEngine::GetInstance()->GetCamera()->GetClippingPlanes().x;
	float tMax = CoreEngine::GetInstance()->GetCamera()->GetClippingPlanes().y;

	glm::vec3 obbPosition_World(box_->transform[3].x,
								box_->transform[3].y,
								box_->transform[3].z);

	glm::vec3 delta = obbPosition_World - ray_->origin;

	//X axis
	glm::vec2 xAxis(box_->transform[0].x, box_->transform[0].y);
	float e = glm::dot(xAxis, delta);
	float f = glm::dot(ray_->direction, xAxis);

	if (fabs(f) > 0.001f) {
		float t1 = (e + box_->minVert.x) / f;
		float t2 = (e + box_->maxVert.x) / f;

		if (t1 > t2) {
			float w = t1;
			t1 = t2;
			t2 = w;
		}

		if (t2 < tMax) {
			tMax = t2;
		}

		if (t1 > tMin) {
			tMin = t1;
		}

		if (tMax < tMin) {
			return false;
		}
	}
	
	else {
		if (-e + box_->minVert.x > 0.0f || -e + box_->maxVert.x < 0.0f) {
			return false;
		}
	}
	//TODO: check for y and z plane

	//Y axis
	glm::vec3 yAxis(box_->transform[1].x, box_->transform[1].y, box_->transform[1].z);
	e = glm::dot(yAxis, delta);
	f = glm::dot(ray_->direction, yAxis);

	if (fabs(f) > 0.001f) {
		float t1 = (e + box_->minVert.y) / f;
		float t2 = (e + box_->maxVert.y) / f;

		if (t1 > t2) {
			float w = t1;
			t1 = t2;
			t2 = w;
		}

		if (t2 < tMax) {
			tMax = t2;
		}

		if (t1 > tMin) {
			tMin = t1;
		}

		if (tMax < tMin) {
			return false;
		}
	}

	else {
		if (-e + box_->minVert.y > 0.0f || -e + box_->maxVert.y < 0.0f) {
			return false;
		}
	}

	ray_->intersectionDist = tMin;
	return true;
}
*/


CollisionDetection::~CollisionDetection()
{
}
