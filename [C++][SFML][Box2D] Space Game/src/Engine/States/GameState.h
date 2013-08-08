#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <memory>

#include <SFML/Graphics/RenderWindow.hpp>

#include "StateManager.h"

class GameState
{
private:
	bool m_paused;
	bool m_flaggedForRemoval;
protected:
	StateManager& m_manager;
	sf::RenderWindow& m_window;
public:
	GameState(StateManager& manager) : 
		m_manager(manager), 
		m_window(manager.getWindow()),
		m_paused(false), 
		m_flaggedForRemoval(false) {}
	virtual ~GameState() {}

	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void handleEvents() = 0;

	void pause() { m_paused = true; }
	void resume() { m_paused = false; }
	bool isRunning() { return m_paused; }

	void flagForRemoval() { m_flaggedForRemoval = true; }
	bool flaggedForRemoval() { return m_flaggedForRemoval; }
};
#endif // GAMESTATE_H
