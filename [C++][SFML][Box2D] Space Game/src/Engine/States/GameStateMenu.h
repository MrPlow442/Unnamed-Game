#ifndef GAMESTATEMENU_H
#define GAMESTATEMENU_H

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include "GameState.h"

class GameStateMenu : public GameState
{
private:
	sf::Text titleText;
public:
	GameStateMenu(StateManager& manager);
	~GameStateMenu();

	void update();
	void draw();
	void handleEvents();
};
#endif // GAMESTATEMENU_H