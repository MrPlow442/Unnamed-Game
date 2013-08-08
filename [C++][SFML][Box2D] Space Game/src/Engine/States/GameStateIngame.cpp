#include "GameStateIngame.h"

//States
//Resource Managers
#include "..\Resource\TextureManager.h"
//Debug
#include "..\Debug\dbgmsg.h"
//Loading
#include "..\LoadingThread.h"
//Standard libraries
#include <chrono>

GameStateIngame::GameStateIngame(StateManager& manager) : 
	GameState(manager),
	m_physicsWorld(b2Vec2(0.f, 0.f)),
	m_velocityIterations(8),
	m_positionIterations(3),
	m_debugDraw(m_window)
{
	DBGMSGR("Constructing " << typeid(*this).name());
	loadingThread.Start(m_window);
	background.setTexture(textureManager.get("stars2.png"));
	textureManager.get("stars2.png").setRepeated(true);
	background.setTextureRect(sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(m_window.getSize())));

	m_debugDraw.SetFlags(b2Draw::e_shapeBit);
	m_physicsWorld.SetDebugDraw(&m_debugDraw);

	std::this_thread::sleep_for(std::chrono::milliseconds(2000)); //Test to see if the thread runs correctly
	loadingThread.End();
}

GameStateIngame::~GameStateIngame()
{
	DBGMSGR("Destructing " << typeid(*this).name());
}

void GameStateIngame::update()
{
	m_physicsWorld.Step(1.f/60.f, m_velocityIterations, m_positionIterations);
}

void GameStateIngame::draw()
{
	m_window.draw(background);
	m_physicsWorld.DrawDebugData();
}

void GameStateIngame::handleEvents()
{
	using namespace sf;
	Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == Event::Closed || (event.type == Event::KeyPressed && (event.key.alt && event.key.code == Keyboard::F4)))
		{
			m_window.close();
		}
	}
}