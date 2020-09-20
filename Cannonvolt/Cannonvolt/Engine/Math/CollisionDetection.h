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

	//TODO: use this for one of the graph things
	static Ray ScreenPosToWorldRay(glm::vec2 mouseCords_, glm::vec2 screenSize_, Camera* camera_);
	//static bool RayObbIntersection(Ray* ray_, BoundingBox* box_);

	//static bool AABB(const glm::vec2 pos1, const glm::vec2 size1, const glm::vec2 pos2, const glm::vec2 size2);

	~CollisionDetection();
};
#endif //! COLLISIONDETECTION_H


