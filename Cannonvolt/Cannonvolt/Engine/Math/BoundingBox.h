#ifndef BOUNDINGBOX_H
#define BOUNDINGBOX_H

#include <glm/glm.hpp>

struct BoundingBox {
public:

	//x = Width, y = Height
	glm::vec2 dimentions;

	glm::vec2 pos;

	inline BoundingBox() {
		dimentions = glm::vec2();
		pos = glm::vec2();
	}

	inline BoundingBox(glm::vec2 dimentions_, glm::vec2 pos_) {
		dimentions = dimentions_;
		pos = pos_;
	}

	//Is not in collision because Screen partition could not access it

	//Both maxs must be larger the the others mins
	inline bool Intersects(BoundingBox* box_) {

		glm::vec2 maxCorner = pos + dimentions;

		glm::vec2 otherMinCorner = box_->pos;
		glm::vec2 otherMaxCorner = box_->pos + box_->dimentions;

		//Self intersect prevention
		if (pos == otherMinCorner && maxCorner == otherMaxCorner) { return false; }

		if (pos.x <= otherMaxCorner.x && otherMinCorner.x <= maxCorner.x  &&
			pos.y <= otherMaxCorner.y && otherMinCorner.y <= maxCorner.y) {
			return true;
		}

		return false;
	}

	inline glm::vec2 CollisionDepth(BoundingBox* box_) {

		glm::vec2 maxCorner = pos + dimentions;

		glm::vec2 otherMinCorner = box_->pos;
		glm::vec2 otherMaxCorner = box_->pos + box_->dimentions;

		glm::vec2 depth(0);

		//First get which side is colliding

		//TODO: test if this works with objects of different size

		//Coming from the right
		float x1 = maxCorner.x - otherMinCorner.x;

		//Coming from the left
		float x2 = otherMaxCorner.x - pos.x;


		//Coming from the top
		float y1 = maxCorner.y - otherMinCorner.y;

		//Coming from the bottom
		float y2 = otherMaxCorner.y - pos.y;

		bool right = false, up = false;

		if (x1 < x2) {
			right = true;
			depth.x = x1;
		}
		else {
			depth.x = x2;
		}

		if (y1 < y2) {
			up = true;
			depth.y = y1;
		}
		else {
			depth.y = y2;
		}

		if (depth.x < depth.y) {
			return glm::vec2((depth.x + 0.4f) * (right ? -1 : 1), 0.0f);
		}
		else {
			return glm::vec2(0.0f, (depth.y + 0.4f) * (up ? -1 : 1));
		}
	}
};


#endif // !BOUNDINGBOX_H
