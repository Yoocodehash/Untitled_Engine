#pragma once

/*
class or struct to hold the information of the sprite, think of it like a model and mesh class together

sprite shoould be able to know the texture (sprite sheet) it is working off of and 
*/

#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Camera/Camera.h"
#include "../../Math/BoundingBox.h"
#include <glew.h>

class GameObject;


//Sprite sheet 

struct Vertex {
    glm::vec2 position;
    glm::vec2 texCoords;
};

class Sprite
{
public:
    Sprite(GLuint shaderProgram_, const std::string& textureName_, GameObject * parent_);
    ~Sprite();

    //Getters
    BoundingBox GetBoundingBox();
    GLuint GetShaderProgram() const;

    glm::vec2 GetDimentions() const;
    glm::vec2 GetScale() const;
    bool GetFlip() const;

    void SetScale(glm::vec2 scale_);

    void Draw(Camera* camera_);

    void SetFlip(bool flip_);




private:
    void InitRenderData();
    GameObject* parent;

    BoundingBox box;
    GLuint shaderProgram;
    std::string textureName;
    GLuint textureID;


    glm::vec2 spriteSize;
    glm::vec2 scale;

    //GLuint textureLoc;

    int depth; //Depth (0 is first rendered)

    bool flip;

    GLuint VAO, VBO;

    GLuint modelLoc, projLoc, color;

    glm::vec4 tint;

    static std::vector<Vertex> boxCoords;
    static std::vector<Vertex> boxCoordsRev;


};

