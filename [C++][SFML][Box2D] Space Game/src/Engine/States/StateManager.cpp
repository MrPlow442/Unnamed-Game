#include "StateManager.h"
#include "GameState.h"
#include "..\DBG\dbgmsg.h"

StateManager::StateManager(sf::RenderWindow &window) : m_window(window)
{}

void StateManager::pushState(std::unique_ptr<GameState> state)
{
	if(state != nullptr) 
	{
		if(!m_gameStates.empty())
		{
			m_gameStates.back()->pause();
		}

		m_gameStates.push_back( std::move(state) );
	}
	else
	{
		DBGMSGR("State is nullptr");
		return; //TODO: Create and throw an exception here
	}
}

void StateManager::popState()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->flagForRemoval();
}

void StateManager::changeState( std::unique_ptr<GameState> state )
{
	if(state != nullptr)
	{
		popState();
		pushState(std::move(state));
	}
	else
	{
		DBGMSGR("State is nullptr");
		return; //TODO: Create and throw an exception here
	}
}

void StateManager::cleanup()
{
	if(!m_gameStates.empty())
	{
		m_gameStates.erase(std::remove_if(m_gameStates.begin(), m_gameStates.end(), 
			[&](const std::unique_ptr<GameState> &state){
				return state->flaggedForRemoval();
		}), m_gameStates.end());
	}
}

void StateManager::update()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->update();
}

void StateManager::draw()
{
	if(!m_gameStates.empty())
	{
		m_window.clear();
		for(std::unique_ptr<GameState> &state : m_gameStates)
		{
			state->draw();
		}
		m_window.display();
	}
}

void StateManager::handleEvents()
{
	if(!m_gameStates.empty())
		m_gameStates.back()->handleEvents();
}

sf::RenderWindow& StateManager::getWindow()
{
	return m_window;
}
