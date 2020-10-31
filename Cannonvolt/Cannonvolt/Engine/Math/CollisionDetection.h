#ifndef COLLISIONDETECTION_H
#define COLLISIONDETECTION_H

#include "../Camera/Camera.h"

/*Function of this class is to detect all types of collisions*/


struct Ray;
struct BoundingBox;

class CollisionDetection
{
public:
	CollisionDetection(const CollisionDetection&) = delete;
	CollisionDetection(CollisionDetection&&) = delete;
	CollisionDetection& operator =(const CollisionDetection&) = delete;
	CollisionDetection& operator =(CollisionDetection&&) = delete;

	CollisionDetection() = delete;

	static Ray ScreenPosToWorldRay(glm::vec2 mouseCords_, glm::vec2 screenSize_, Camera* camera_);
	//static bool RayObbIntersection(Ray* ray_, BoundingBox* box_);

	~CollisionDetection();
};
#endif //! COLLISIONDETECTION_H


