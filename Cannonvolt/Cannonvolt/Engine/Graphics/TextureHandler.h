#ifndef TEXTUREHANDLER_H
#define TEXTUREHANDLER_H

#include <memory>
#include <string>
#include <vector>
#include <SDL.h>
#include <SDL_image.h>
#include <glew.h>

#include "../Core/Debug.h"

struct Texture {
	GLuint textureID = 0;
	float textureWidth = 0.0f;
	float textureHeight = 0.0f;
	float spriteWidth = 0.0f;
	float spriteHeight = 0.0f;
	std::string textureName = "";

};

//Texture repository and loader

class TextureHandler
{
public:
	TextureHandler(const TextureHandler&) = delete;
	TextureHandler(TextureHandler&&) = delete;
	TextureHandler& operator =(const TextureHandler&) = delete;
	TextureHandler& operator =(TextureHandler&&) = delete;

	static TextureHandler* GetInstance();
	void OnDestroy();

	
	void CreateTexture(const std::string& textureName_,
		const std::string& textureFilePath_, const float spriteWidth_ = 0.0f,
		const float spriteHeight = 0.0f);
	const GLuint GetTexture(const std::string textureName_);
	const Texture* GetTextureData(const std::string& textureName_);

private:
	TextureHandler();
	~TextureHandler();

	static std::unique_ptr<TextureHandler> textureInstance;
	friend std::default_delete<TextureHandler>;
	static std::vector<Texture*> textures;
};

#endif