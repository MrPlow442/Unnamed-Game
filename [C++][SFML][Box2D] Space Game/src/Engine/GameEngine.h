#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SFML\Window.hpp>
#include <SFML\Graphics.hpp>
#include <SFML\System.hpp>

//Game States
#include "States\StateManager.h"
#include "States\GameStateIntro.h"
#include "States\GameStateMenu.h"
#include "States\GameStateIngame.h"

class GameEngine final
{
private:
	sf::RenderWindow m_window;
	StateManager m_stateManager;
public:
	GameEngine(sf::VideoMode mode, const sf::String& title, bool fullscreen, const sf::ContextSettings& settings = sf::ContextSettings());
	void run();
};
#endif // GAMEENGINE_H
