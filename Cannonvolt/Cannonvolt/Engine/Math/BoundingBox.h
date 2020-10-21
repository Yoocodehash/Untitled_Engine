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


		return false;
	}

private:
	inline glm::vec2 GetTransformedPoint(glm::vec2 position_, glm::vec2 dimentions_ = glm::vec2(0)) {
		return glm::vec2(position_.x, position_.y) + dimentions_;
	}
};


#endif // !BOUNDINGBOX_H
