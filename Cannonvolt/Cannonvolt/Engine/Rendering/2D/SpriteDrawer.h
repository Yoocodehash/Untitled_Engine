#pragma once
#include "../../Camera/Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "../../Graphics/ShaderHandler.h"
#include "../../Graphics/TextureHandler.h"
#include "../../Math/BoundingBox.h"

struct Vertex {
	glm::vec2 position;
	glm::vec2 texCoords;
};

class SpriteDrawer {
public:
	SpriteDrawer(std::string textureTag_, GLuint shaderProgram_);
	~SpriteDrawer();

	void Draw(Camera* camera_, std::vector<glm::mat4> instances);

private:
	void InitRenderData();
	std::string textureTag; //Used in render to denote what texture should loaded in here
	GLuint shaderProgram;

	GLuint VAO, VBO;
	
	GLuint modelLoc, projLoc, color;

	std::vector<Vertex> boxCoords;
	std::vector<Vertex> boxCoordsRev;

};