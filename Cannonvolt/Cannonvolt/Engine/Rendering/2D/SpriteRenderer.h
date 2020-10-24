#pragma once
#include "../../Camera/Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Graphics/ShaderHandler.h"
#include "../../Graphics/TextureHandler.h"
#include "../../Math/BoundingBox.h"

class SpriteRenderer {
public:
	SpriteRenderer(std::string textureTag_, GLuint shaderProgram_);
	~SpriteRenderer();

	void Draw(Camera* camera_, std::vector<glm::mat4> instances);

private:
	void InitRenderData();
	std::string textureTag; //Used in render to denote what texture should loaded in here
	GLuint shaderProgram;

	unsigned int quadVAO;
	GLuint modelLoc, projLoc, color;

;
};