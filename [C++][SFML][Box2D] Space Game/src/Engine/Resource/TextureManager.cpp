#include "TextureManager.h"

TextureManager textureManager("res\\");

TextureManager::TextureManager(const std::string &path) : ResourceManager(path)
{}

TextureManager::~TextureManager()
{}

bool TextureManager::load(const std::string &name )
{
	m_resourceMap.insert(std::make_pair(name, std::unique_ptr<sf::Texture>(new sf::Texture())));
	return m_resourceMap.at(name)->loadFromFile(m_directoryPath + "\\" + name);
}
