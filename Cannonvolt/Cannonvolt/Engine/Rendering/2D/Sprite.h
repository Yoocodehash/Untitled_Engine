#pragma once

/*
class or struct to hold the information of the sprite, think of it like a model and mesh class together

sprite shoould be able to know the texture (sprite sheet) it is working off of and 
*/
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Graphics/ResourceManager.h"
#include "../../Math/BoundingBox.h"
#include "../../Camera/Camera.h"

class Sprite
{
public:
    Sprite(GLuint shaderProgram);
    ~Sprite();
    
    void DrawSprite(Texture2D& texture, glm::vec3 color = glm::vec3(1.0f));

    BoundingBox GetBoundingBox();
    glm::mat4 GetTransform();

    void Render(Camera* camera_);


private:
    BoundingBox box;
    GLuint shaderProgram;
    Texture2D* texture;
    unsigned int quadVAO;

    glm::vec3 position; //Position of sprite
    float rotation; //Rotation of sprite
    glm::vec3 scale; //Scale of sprite
    int depth; //Depth (0 is first rendered)

    void initRenderData();
};

