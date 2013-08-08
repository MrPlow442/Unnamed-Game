#include "SoundManager.h"

SoundManager soundManager("res\\");

SoundManager::SoundManager( const std::string &path ) : ResourceManager(path)
{}

SoundManager::~SoundManager()
{}

bool SoundManager::load( const std::string &name )
{
	m_resourceMap.insert(std::make_pair(name, std::unique_ptr<sf::SoundBuffer>(new sf::SoundBuffer)));
	return m_resourceMap.at(name)->loadFromFile(m_directoryPath + "\\" + name);
}
