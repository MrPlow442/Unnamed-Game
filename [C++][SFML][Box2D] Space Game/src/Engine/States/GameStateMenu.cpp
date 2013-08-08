#include "GameStateMenu.h"

//States
#include "GameStateIngame.h"
//Resource Managers
#include "..\Resource\FontManager.h"
//Debug
#include "..\Debug\dbgmsg.h"

GameStateMenu::GameStateMenu(StateManager& manager) : 
	GameState(manager), 
	titleText("Menu State", fontManager.get("LeagueGothic-Regular.otf"), 70U)
{
	DBGMSGR("Constructing " << typeid(*this).name());
}

GameStateMenu::~GameStateMenu()
{
	DBGMSGR("Destructing " << typeid(*this).name());
}

void GameStateMenu::update()
{}

void GameStateMenu::draw()
{
	m_window.draw(titleText);
}

void GameStateMenu::handleEvents()
{
	using namespace sf;
	Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == Event::Closed || (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
		{
			m_window.close();
		}
		if(event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
		{
			m_manager.changeState(std::unique_ptr<GameState>( new GameStateIngame(m_manager)));
		}
	}
}
