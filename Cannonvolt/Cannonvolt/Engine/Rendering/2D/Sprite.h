#pragma once

/*
class or struct to hold the information of the sprite, think of it like a model and mesh class together

sprite shoould be able to know the texture (sprite sheet) it is working off of and 
*/
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "../../Graphics/ShaderHandler.h"
#include "../../Graphics/TextureHandler.h"
#include "../../Math/BoundingBox.h"
#include "../../Camera/Camera.h"
#include <glm/gtc/type_ptr.hpp>

//Sprite sheet 

class Sprite
{
public:
    Sprite(GLuint shaderProgram_,std::string textureTag_);
    ~Sprite();


    //Getters
    BoundingBox GetBoundingBox();
    glm::mat4 GetTransform();
    glm::vec3 GetPosition();
    float GetRotation();
    glm::vec3 GetScale();
    GLuint GetShaderProgram() const;


    //Setters 
    //passes vec2 in order to prevent changes to z axis
    void SetPosition(glm::vec2 position_);
    void SetRotation(float rotation_);
    void SetScale(glm::vec2 scale_);


    void Render(Camera* camera_);


private:
    BoundingBox box;
    GLuint shaderProgram;
    std::string textureTag; //Used in render to denote what texture should loaded in here
 
    unsigned int quadVAO;
    GLuint modelLoc, projLoc;

    //GLuint textureLoc;
    //GLuint viewPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;

    glm::vec3 position; //Position of sprite
    float rotation; //Rotation of sprite
    glm::vec3 scale; //Scale of sprite
    int depth; //Depth (0 is first rendered)

    void initRenderData();
};

