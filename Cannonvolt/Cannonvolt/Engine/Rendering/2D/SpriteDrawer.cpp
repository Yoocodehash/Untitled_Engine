#include "SpriteDrawer.h"
//#include "../../Core/CoreEngine.h"

SpriteDrawer::SpriteDrawer(std::string textureTag_, GLuint shaderProgram_) {
    textureTag = textureTag_;
    shaderProgram = shaderProgram_;

    boxCoords.reserve(6);
    boxCoords.push_back(Vertex());
    boxCoords.push_back(Vertex());
    boxCoords.push_back(Vertex());
    boxCoords.push_back(Vertex());
    boxCoords.push_back(Vertex());
    boxCoords.push_back(Vertex());

    boxCoords[0].position = glm::vec2(0.0f, 1.0f);
    boxCoords[0].texCoords = glm::vec2(0.0f, 0.0f);

    boxCoords[1].position = glm::vec2(1.0f, 0.0f);
    boxCoords[1].texCoords = glm::vec2(1.0f, 1.0f);

    boxCoords[2].position = glm::vec2(0.0f, 0.0f);
    boxCoords[2].texCoords = glm::vec2(0.0f, 1.0f);

    boxCoords[3].position = glm::vec2(0.0f, 1.0f);
    boxCoords[3].texCoords = glm::vec2(0.0f, 0.0f);
    
    boxCoords[4].position = glm::vec2(1.0f, 1.0f);
    boxCoords[4].texCoords = glm::vec2(1.0f, 0.0f);

    boxCoords[5].position = glm::vec2(1.0f, 0.0f);
    boxCoords[5].texCoords = glm::vec2(1.0f, 1.0f);



    InitRenderData();
}

SpriteDrawer::~SpriteDrawer()
{
}
void SpriteDrawer::InitRenderData()
{
    // configure VAO/VBO

    glGenVertexArrays(1, &VAO);
    glGenBuffers(1, &VBO);

    glBindVertexArray(VAO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, boxCoords.size() * sizeof(Vertex), &boxCoords[0], GL_STATIC_DRAW);

    //POSITION
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)0);

    //TEXTURE COORDINATES
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (GLvoid*)offsetof(Vertex, texCoords));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    modelLoc = glGetUniformLocation(shaderProgram, "model");
    projLoc = glGetUniformLocation(shaderProgram, "projection");
    color = glGetUniformLocation(shaderProgram, "spriteColor");


    //Camera Loc

    //viewPositionLoc = glGetUniformLocation(shaderProgram, "cameraPos");
}

void SpriteDrawer::Draw(Camera* camera_, std::vector<glm::mat4> instances)
{
    
    glUniform1f(TextureHandler::GetInstance()->GetTexture(textureTag), 0);

    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_2D, TextureHandler::GetInstance()->GetTexture(textureTag));

    glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(camera_->GetOrthographic()));

    //Color filter
    glUniform3f(color, 1.0f, 1.0f, 1.0f);


    //TODO: add in parsing for the sprite sheet
    //glBindTexture(GL_TEXTURE_2D, TextureHandler::GetInstance()->GetTexture(textureTag));

    glBindVertexArray(VAO);
    for (int i = 0; i < instances.size(); i++) {
        glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(instances[i]));
        glDrawArrays(GL_TRIANGLES, 0, 6);
    }

    glBindVertexArray(0);
    glBindTexture(GL_TEXTURE_2D, 0);
}
