#include "SpriteRenderer.h"
//#include "../../Core/CoreEngine.h"

SpriteRenderer::SpriteRenderer(std::string textureTag_, GLuint shaderProgram_) {
    textureTag = textureTag_;
    shaderProgram = shaderProgram_;
    InitRenderData();

}

SpriteRenderer::~SpriteRenderer()
{
}
void SpriteRenderer::InitRenderData()
{
    // configure VAO/VBO
    unsigned int VBO;

    //The reason the y texture vertacies are reversed is becasue images consider the top 0 but opengl considers the bottom to be 0
    float vertices[] = {
        // pos      // tex
         0.0f, 1.0f, 0.0f, 0.0f,
         1.0f, 0.0f, 1.0f, 1.0f,
         0.0f, 0.0f, 0.0f, 1.0f,

         0.0f, 1.0f, 0.0f, 0.0f,
         1.0f, 1.0f, 1.0f, 0.0f,
         1.0f, 0.0f, 1.0f, 1.0f
         
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

    modelLoc = glGetUniformLocation(shaderProgram, "model");
    projLoc = glGetUniformLocation(shaderProgram, "projection");
    color = glGetUniformLocation(shaderProgram, "spriteColor");


    //Camera Loc

    //viewPositionLoc = glGetUniformLocation(shaderProgram, "cameraPos");
}

void SpriteRenderer::Draw(Camera* camera_, std::vector<glm::mat4> instances)
{
    
    glUniform1f(TextureHandler::GetInstance()->GetTexture(textureTag), 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TextureHandler::GetInstance()->GetTexture(textureTag));

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetOrthographic()));

    //Color filter
    glUniform3f(color, 1.0f, 1.0f, 1.0f);


    //TODO: add in parsing for the sprite sheet
    //glBindTexture(GL_TEXTURE_2D, TextureHandler::GetInstance()->GetTexture(textureTag));

    glBindVertexArray(this->quadVAO);
    for (int i = 0; i < instances.size(); i++) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances[i]));
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
