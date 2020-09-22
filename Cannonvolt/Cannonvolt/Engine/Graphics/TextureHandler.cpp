#include "TextureHandler.h"


std::unique_ptr<TextureHandler> TextureHandler::textureInstance = nullptr;
std::vector<Texture*> TextureHandler::textures = std::vector<Texture*>();

TextureHandler* TextureHandler::GetInstance()
{
	if (textureInstance.get() == nullptr) {
		textureInstance.reset(new TextureHandler);
	}
	return textureInstance.get();
}

void TextureHandler::OnDestroy()
{
	if (textures.size() > 0) {
		for (auto t : textures) {
			glDeleteTextures(sizeof(GLuint), &t->textureID);
			delete t;
			t = nullptr;
		}
		textures.clear();
	}
}

void TextureHandler::CreateTexture(const std::string& textureName_,
	const std::string& textureFilePath_, const float spriteWidth_, 
	const float spriteHeight_)
{
	Texture* t = new Texture();
	SDL_Surface* surface = nullptr;
	surface = IMG_Load(textureFilePath_.c_str());
	if (surface == nullptr) {
		Debug::Error("Surface failed to load " + textureName_,
			"TextureHandler.cpp", __LINE__);
		delete t;
		t = nullptr;
		return;
	}
	glGenTextures(1, &t->textureID);
	glBindTexture(GL_TEXTURE_2D, t->textureID);

	int mode = surface->format->BytesPerPixel == 4 ? GL_RGBA : GL_RGB;


	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexImage2D(GL_TEXTURE_2D, 0, mode, surface->w, surface->h, 0,
		mode, GL_UNSIGNED_BYTE, surface->pixels);


	glGenerateMipmap(GL_TEXTURE_2D);

	glBindTexture(GL_TEXTURE_2D, 0);

	t->textureWidth = surface->w;
	t->textureHeight = surface->h;
	t->textureName = textureName_;
	t->spriteWidth = spriteWidth_;
	t->spriteHeight = spriteHeight_;

	textures.push_back(t);

	SDL_FreeSurface(surface);
	surface = nullptr;
}

const GLuint TextureHandler::GetTexture(const std::string textureName_)
{
	for (auto t : textures) {
		if (t->textureName == textureName_) {
			return t->textureID;
		}
	}
	return 0;
}

const Texture* TextureHandler::GetTextureData(const std::string& textureName_)
{
	for (auto t : textures) {
		if (t->textureName == textureName_) {
			return t;
		}
	}
	return 0;
}

const void TextureHandler::InitTexture(const std::string fileName_)
{
	//Try and get texture
	GLuint currentTexture = TextureHandler::GetInstance()->GetTexture(fileName_);

	//Create texture if it is not loaded
	if (currentTexture == 0) {
		//Get the width and height from the sizeFile
		std::string sizeFile = "./Resources/Textures/" + fileName_ + ".txt";
		if (sizeFile == "") {
			Debug::Error("SizeFile failed to load " + fileName_,
				"TextureHandler.cpp", __LINE__);
			return;
		}
		std::ifstream in(sizeFile.c_str(), std::ios::in);
		std::string line;
		std::getline(in, line);
		std::istringstream v(line);
		float width, height;
		v >> width >> height;


		TextureHandler::GetInstance()->CreateTexture(fileName_,
		"./Resources/Textures/" + fileName_ + ".jpg", width, height);
	}
}

TextureHandler::TextureHandler()
{
	textures.reserve(10);
}


TextureHandler::~TextureHandler()
{
	OnDestroy();
}