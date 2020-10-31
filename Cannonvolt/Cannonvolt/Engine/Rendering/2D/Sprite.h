#pragma once

/*
class or struct to hold the information of the sprite, think of it like a model and mesh class together

sprite shoould be able to know the texture (sprite sheet) it is working off of and 
*/

#include "SpriteDrawer.h"


//Sprite sheet 

class Sprite
{
public:
    Sprite(GLuint shaderProgram_, const std::string& textureName_);
    ~Sprite();

    const int CreateInstance(glm::vec2 position_, float rotation_, glm::vec2 scale_);
    void UpdateInstance(int index_, glm::vec2 position_, float rotation_, glm::vec2 scale_);

    //Getters
    BoundingBox GetBoundingBox();
    glm::mat4 GetTransform(int index_) const;
    GLuint GetShaderProgram() const;

    glm::vec2 GetDimentions() const;

    void Draw(Camera* camera_);

    void SetFlip(bool flip_);


private:

    SpriteDrawer* spriteRender;
    BoundingBox box;
    GLuint shaderProgram;
 
    glm::vec2 spriteSize;
    //GLuint textureLoc;

    int depth; //Depth (0 is first rendered)

    glm::mat4 GetTransform(glm::vec2 position_, float rotation_,
        glm::vec2 scale_) const;

    std::vector<glm::mat4> spriteInstances;

    bool flip;
};

