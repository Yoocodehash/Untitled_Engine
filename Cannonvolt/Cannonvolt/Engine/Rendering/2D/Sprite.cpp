#include "Sprite.h"
#include "../../Core/CoreEngine.h"
Sprite::Sprite(GLuint shaderProgram_, const std::string& textureName_) : depth(0), quadVAO(1), rotation(0)
{
    shaderProgram = shaderProgram_;
    textureTag = textureName_;
    TextureHandler::GetInstance()->InitTexture(textureName_);
    box = BoundingBox(TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteWidth,
        TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteHeight,
        GetTransform());
    SceneGraph::GetInstance()->AddSprite(this);

    initRenderData();
}

Sprite::~Sprite()
{
}

BoundingBox Sprite::GetBoundingBox()
{
    return box;
}

glm::mat4 Sprite::GetTransform()
{
    glm::mat4 model;

    model = glm::translate(model, position);

    
    model = glm::translate(model, glm::vec3(0.5f * scale.x, 0.5f * scale.y, 0.0f)); // move origin of rotation to center of quad
    model = glm::rotate(model, glm::radians(rotation + 180), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate
    model = glm::translate(model, glm::vec3(-0.5f * scale.x, -0.5f * scale.y, 0.0f)); // move origin back

    model = glm::scale(model, scale);

    

    return model;
}

glm::vec3 Sprite::GetPosition()
{
    return position;
}

float Sprite::GetRotation()
{
    return rotation;
}

glm::vec3 Sprite::GetScale()
{
    return scale;
}

GLuint Sprite::GetShaderProgram() const
{
    return shaderProgram;
}

void Sprite::initRenderData()
{
    // configure VAO/VBO
    unsigned int VBO;
    float vertices[] = {
        // pos      // tex
        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
    };
      /*0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f,
        0.0f, 0.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f
        
        
                1.0f, 0.0f, 0.0f, 1.0f,
        0.0f, 1.0f, 1.0f, 0.0f,
        1.0f, 1.0f, 0.0f, 0.0f,

        0.0f, 1.0f, 0.0f, 1.0f,
        1.0f, 1.0f, 1.0f, 1.0f,
        1.0f, 0.0f, 1.0f, 0.0f*/
    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    modelLoc = glGetUniformLocation(shaderProgram, "model");
    projLoc = glGetUniformLocation(shaderProgram, "projection");
    color = glGetUniformLocation(shaderProgram, "spriteColor");

    
    //Camera Loc

    //viewPositionLoc = glGetUniformLocation(shaderProgram, "cameraPos");
}

void Sprite::SetPosition(glm::vec2 position_)
{
    position = glm::vec3(position_, 0);
}

void Sprite::SetRotation(float rotation_)
{
    rotation = rotation_;
}

void Sprite::SetScale(glm::vec2 scale_)
{
    scale = glm::vec3(scale_, 0);
}

void Sprite::Render(Camera* camera_)
{
    //Could this system have worked? mabye look into blend for thesprite sheet parse
   // glEnable(GL_TEXTURE_2D);
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //GL Proejction
    //GL othertographic
    //gl model view

    //Update model?


    //TODO: try and fix the fact that the image is not showing up, though alot of other work has been completed
    glUniform1f(TextureHandler::GetInstance()->GetTexture(textureTag), 0);
    //glScalef(1, -1, 1);
    glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(GetTransform()));
    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetOrthographic()));

    //Color filter
    glUniform3f(color, 1.0f, 1.0f, 1.0f);

    glActiveTexture(GL_TEXTURE0);
    //TODO: add in parsing for the sprite sheet
    glBindTexture(GL_TEXTURE_2D, TextureHandler::GetInstance()->GetTexture(textureTag));

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}