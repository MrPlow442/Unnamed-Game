#include "FontManager.h"

FontManager fontManager("res\\");

FontManager::FontManager(const std::string path ) : ResourceManager(path)
{}

FontManager::~FontManager()
{}

bool FontManager::load( const std::string &name )
{
	m_resourceMap.insert(std::make_pair(name, std::unique_ptr<sf::Font>(new sf::Font)));
	return m_resourceMap.at(name)->loadFromFile(m_directoryPath + "\\" + name);
}

