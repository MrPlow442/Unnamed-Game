#ifndef FONTMANAGER_H
#define FONTMANAGER_H

#include <string>
#include <iostream>

#include <SFML\Graphics\Font.hpp>

#include "ResourceManager.h"

class FontManager;

extern FontManager fontManager;

class FontManager : public ResourceManager<sf::Font>
{
private:
	bool load(const std::string &name);
public:
	FontManager(const std::string path);
	~FontManager();
};
#endif // FONTMANAGER_H
