#pragma once

/*
class or struct to hold the information of the sprite, think of it like a model and mesh class together

sprite shoould be able to know the texture (sprite sheet) it is working off of and 
*/

#include "SpriteRenderer.h"


//Sprite sheet 

class Sprite
{
public:
    Sprite(GLuint shaderProgram_, const std::string& textureName_);
    ~Sprite();

    const int CreateInstance(glm::vec3 position_, float rotation_, glm::vec3 scale_);
    void UpdateInstance(int index_, glm::vec3 position_, float rotation_, glm::vec3 scale_);

    //Getters
    BoundingBox GetBoundingBox();
    glm::mat4 GetTransform(int index_) const;
    GLuint GetShaderProgram() const;


    void Render(Camera* camera_);


private:
    SpriteRenderer* spriteRender;
    BoundingBox box;
    GLuint shaderProgram;
 


    //GLuint textureLoc;
    //GLuint viewPositionLoc, lightPosLoc, lightAmbientLoc, lightDiffuseLoc, lightColourLoc;

    int depth; //Depth (0 is first rendered)

    glm::mat4 GetTransform(glm::vec3 position_, float rotation_,
        glm::vec3 scale_) const;

    std::vector<glm::mat4> spriteInstances;
};

