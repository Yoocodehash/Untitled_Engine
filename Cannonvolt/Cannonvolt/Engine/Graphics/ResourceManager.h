#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H



#include <SDL.h>
#include <SDL_image.h>
#include <map>
#include <string>
#include "texture.h"
#include "shader.h"


// A static singleton ResourceManager class that hosts several
// functions to load Textures and Shaders. Each loaded texture
// and/or shader is also stored for future reference by string
// handles. All functions and resources are static and no 
// public constructor is defined
class ResourceManager
{
public:
    ResourceManager(const ResourceManager&) = delete;
    ResourceManager(ResourceManager&&) = delete;
    ResourceManager& operator =(const ResourceManager&) = delete;
    ResourceManager& operator =(ResourceManager&&) = delete;

    static ResourceManager* GetInstance();

    // resource storage
    static std::map<std::string, Shader> Shaders;
    static std::map<std::string, Texture2D> Textures;

    // loads (and generates) a shader program from file loading vertex, fragment shader's source code.
    Shader LoadShader(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile, std::string name);
    // retrieves a stored sader
    Shader GetShader(std::string name);
    // loads (and generates) a texture from file
    Texture2D LoadTexture(const std::string* filePath_, bool alpha, std::string name);
    // retrieves a stored texture
    Texture2D GetTexture(std::string name);
    // properly de-allocates all loaded resources
    void Clear();
private:
    // private constructor, that is we do not want any actual resource manager objects. Its members and functions should be publicly available (static).
    ResourceManager() { }
    ~ResourceManager() { };

    static std::unique_ptr<ResourceManager> resourceManagerInstance;
    friend std::default_delete<ResourceManager>;

    // loads and generates a shader from file
    Shader loadShaderFromFile(const char* vShaderFile, const char* fShaderFile, const char* gShaderFile = nullptr);
    // loads a single texture from file
    Texture2D loadTextureFromFile(const std::string* filePath_, bool alpha, std::string name_);
};

#endif