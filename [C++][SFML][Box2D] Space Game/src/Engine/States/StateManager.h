#ifndef STATEMANAGER_H
#define STATEMANAGER_H

#include <memory>
#include <vector>
#include <algorithm>
#include <iostream>
#include <SFML/Graphics/RenderWindow.hpp>

class GameState;

class StateManager
{
private:
	std::vector< std::unique_ptr<GameState> > m_gameStates;
	sf::RenderWindow &m_window;
public:
	StateManager(sf::RenderWindow &window);

	void changeState(std::unique_ptr<GameState> state);
	void pushState(std::unique_ptr<GameState> state);
	void popState();
	void cleanup();

	void update();
	void draw();
	void handleEvents();

	sf::RenderWindow& getWindow();
};

#endif // STATEMANAGER_H
