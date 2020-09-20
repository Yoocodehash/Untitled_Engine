#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>

struct BoundingBox {
public:
	glm::vec2 minVert, maxVert;
	glm::mat4 transform;

	inline BoundingBox() {
		minVert = glm::vec2();
		maxVert = glm::vec2();
		transform = glm::mat4();
	}

	inline BoundingBox(glm::vec2 minVert_, glm::vec2 maxVert_, glm::mat4 transform_) {
		minVert = minVert_;
		maxVert = maxVert_;
		transform = transform_;
	}

	inline bool Intersects(BoundingBox* box_) {
		glm::vec2 minCorner = GetTransformedPoint(minVert, transform);
		glm::vec2 maxCorner = GetTransformedPoint(maxVert, transform);

		glm::vec2 otherMinCorner = GetTransformedPoint(box_->minVert, box_->transform);
		glm::vec2 otherMaxCorner = GetTransformedPoint(box_->maxVert, box_->transform);
		
		if (minCorner.x <= otherMaxCorner.x && maxCorner.x >= otherMinCorner.x &&
			minCorner.y <= otherMaxCorner.y && maxCorner.y >= otherMinCorner.y) {
			return true;
		}

		return false;
	}

private:
	//Possible error for the transform (do 2d objects have transforms?)
	inline glm::vec2 GetTransformedPoint(glm::vec2 point_, glm::mat4 transform_) {
		return glm::vec2(transform_[3].x, transform_[3].y) + point_;
	}
};


#endif // !BOUNDINGBOX_H
