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
	inline bool Intersects(BoundingBox* box_) {

		glm::vec2 minCorner = pos;
		glm::vec2 maxCorner = GetTransformedPoint(pos, dimentions);

		glm::vec2 otherMinCorner = box_->pos;
		glm::vec2 otherMaxCorner = GetTransformedPoint(box_->pos, box_->dimentions);

		//Both maxs must be larger the the others mins

		if (minCorner.x <= otherMaxCorner.x && maxCorner.x >= otherMinCorner.x &&
			minCorner.y <= otherMaxCorner.y && maxCorner.y >= otherMinCorner.y) {
			return true;
		}

		return false;
	}

	inline glm::vec2 CollisionDepth(BoundingBox* box_) {
		glm::vec2 minCorner = pos;
		glm::vec2 maxCorner = GetTransformedPoint(pos, dimentions);

		glm::vec2 otherMinCorner = box_->pos;
		glm::vec2 otherMaxCorner = GetTransformedPoint(box_->pos, box_->dimentions);

		glm::vec2 depth(0);

		//First get which side is colliding

		//TODO: test if this works with objects of different size


		//Coming from the right
		float x1 = maxCorner.x - otherMinCorner.x;

		//Coming from the left
		float x2 = otherMaxCorner.x - minCorner.x;


		//Coming from the top
		float y1 = maxCorner.y - otherMinCorner.y;

		//Coming from the bottom
		float y2 = otherMaxCorner.y - minCorner.y;

		if (x1 < x2) {
			depth.x = -x1;
		}
		else if (x2 < x1) {
			depth.x = x2;
		}

		if (y1 < y2) {
			depth.y = -y1;
		}
		else if (y2 < y1) {
			depth.y = y2;
		}

		return depth;
	}

private:
	inline glm::vec2 GetTransformedPoint(glm::vec2 position_, glm::vec2 dimentions_ = glm::vec2(0)) {
		return glm::vec2(position_.x, position_.y) + dimentions_;
	}
};


#endif // !BOUNDINGBOX_H
