#include "Sprite.h"

Sprite::Sprite(GLuint shaderProgram_) : depth(0), quadVAO(1), rotation(0)
{
    shaderProgram = shaderProgram_;
}

Sprite::~Sprite()
{
}

void Sprite::DrawSprite(Texture2D& texture, glm::vec3 color)
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
    model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
    model = glm::scale(model, scale);

    return model;
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

    glGenVertexArrays(1, &this->quadVAO);
    glGenBuffers(1, &VBO);

    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

    glBindVertexArray(this->quadVAO);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(float), (void*)0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Sprite::Render(Camera* camera_)
{
    // prepare transformations
    ResourceManager::GetInstance()->GetShader(.Use();

    //TODO:transfer this to updating model/Get Transform

    //model = glm::translate(model, glm::vec3(0.5f * size.x, 0.5f * size.y, 0.0f));
    //model = glm::rotate(model, glm::radians(rotate), glm::vec3(0.0f, 0.0f, 1.0f));
    //model = glm::translate(model, glm::vec3(-0.5f * size.x, -0.5f * size.y, 0.0f));

 //   model = glm::scale(model, size);

    ResourceManager::GetInstance()->GetShader("sprite").Use().SetInteger("im
glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, position);
    age", 0);
        ResourceManager::GetInstance()->GetShader("sprite").SetMatrix4("projection", projection);
    this->shader.SetMatrix4("model", model);
    this->shader.SetVector3f("spriteColor", color);

    glActiveTexture(GL_TEXTURE0);
    texture.Bind();

    glBindVertexArray(this->quadVAO);
    glDrawArrays(GL_TRIANGLES, 0, 6);
    glBindVertexArray(0);
}
