#include "Sprite.h"
#include "../../Core/CoreEngine.h"
Sprite::Sprite(GLuint shaderProgram_, const std::string& textureName_) : depth(0), spriteSize(0)
{
    shaderProgram = shaderProgram_;
    //textureTag = textureName_;
    TextureHandler::GetInstance()->InitTexture(textureName_);
    spriteRender = new SpriteRenderer(textureName_, shaderProgram);

    spriteSize = glm::vec2(TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteWidth,
        TextureHandler::GetInstance()->GetTextureData(textureName_)->spriteHeight);

    box = BoundingBox(spriteSize, glm::vec2(0));

    SceneGraph::GetInstance()->AddSprite(this);
}

Sprite::~Sprite()
{

}

const int Sprite::CreateInstance(glm::vec2 position_, float rotation_, glm::vec2 scale_)
{
    spriteInstances.push_back(GetTransform(position_, rotation_, scale_));
    return spriteInstances.size() - 1;
}

void Sprite::UpdateInstance(int index_, glm::vec2 position_, float rotation_, glm::vec2 scale_)
{
    spriteInstances[index_] = GetTransform(position_, rotation_, scale_);
}

BoundingBox Sprite::GetBoundingBox()
{
    return box;
}

glm::mat4 Sprite::GetTransform(int index_) const
{
    return spriteInstances[index_];
}


GLuint Sprite::GetShaderProgram() const
{
    return shaderProgram;
}

glm::vec2 Sprite::GetDimentions() const
{
    return spriteSize;
}

glm::mat4 Sprite::GetTransform(glm::vec2 position_, float rotation_, glm::vec2 scale_) const
{
    glm::mat4 model = glm::mat4(1.0f);

    glm::vec2 newScale = scale_ * spriteSize;

    model = glm::translate(model, glm::vec3(position_,0));
    model = glm::translate(model, glm::vec3(0.5f * newScale.x, 0.5f * newScale.y, 0.0f)); // move origin of rotation to center of quad
    model = glm::rotate(model, glm::radians(rotation_), glm::vec3(0.0f, 0.0f, 1.0f)); // rotate
    model = glm::translate(model, glm::vec3(-0.5f * newScale.x, -0.5f * newScale.y, 0.0f)); // move origin back
    model = glm::scale(model, glm::vec3(newScale ,0));

    return model;
}

void Sprite::Draw(Camera* camera_)
{
    spriteRender->Draw(camera_, spriteInstances);
    //Could this system have worked? mabye look into blend for thesprite sheet parse
   // glEnable(GL_TEXTURE_2D);
   // glEnable(GL_BLEND);
   // glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    //GL Proejction
    //GL othertographic
    //gl model view

}
