#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <string>

#include <SFML\Audio\SoundBuffer.hpp>

#include "ResourceManager.h"

class SoundManager;

extern SoundManager soundManager;

class SoundManager : public ResourceManager<sf::SoundBuffer>
{
private:
	bool load(const std::string &name);
public:
	SoundManager(const std::string &path);
	~SoundManager();
};
#endif // SOUNDMANAGER_H
