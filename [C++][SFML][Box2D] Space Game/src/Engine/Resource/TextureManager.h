#ifndef TEXTUREMANAGER_H
#define TEXTUREMANAGER_H

#include <SFML\Graphics\Texture.hpp>

#include "ResourceManager.h"

class TextureManager;

extern TextureManager textureManager;

class TextureManager : public ResourceManager<sf::Texture>
{
private:
	bool load(const std::string &name);
public:
	TextureManager(const std::string &path);
	~TextureManager();
};
#endif // TEXTUREMANAGER_H



