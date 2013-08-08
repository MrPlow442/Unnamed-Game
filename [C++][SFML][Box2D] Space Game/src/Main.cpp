#include <SFML\Window\VideoMode.hpp>
#include "Engine\GameEngine.h"

int main()
{
	//Initializing the game window
	unsigned int width = 800;
	unsigned int height = 600;
	unsigned int bpp = 32;

	GameEngine engine(sf::VideoMode(width, height, bpp), "Space Game", false);

	engine.run();
	return 0;
}