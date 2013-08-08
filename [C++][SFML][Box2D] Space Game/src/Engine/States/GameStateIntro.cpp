#include "GameStateIntro.h"

//States
#include "GameStateMenu.h"
//Resource Managers
#include "..\Resource\TextureManager.h"
//Utils
#include "..\Utils\Utils.h"
//Debug
#include "..\DBG\dbgmsg.h"

GameStateIntro::GameStateIntro(StateManager &manager) :
	GameState(manager),
	fadeDirection(In)
{	
	DBGMSGR("Constructing " << typeid(*this).name());
	//preload resources
	textureManager.preload("SFML2.png");
	textureManager.preload("box2d.png");
	//set first icon
	m_introIcon.setTexture(textureManager.get("SFML2.png"));
	centerIcon(m_introIcon);
	util::setAlpha(m_introIcon, 0);
}

GameStateIntro::~GameStateIntro()
{
	DBGMSGR("Destructing " << typeid(*this).name());
	textureManager.erase("SFML2.png");
	textureManager.erase("box2d.png");
}

void GameStateIntro::centerIcon(sf::Sprite &icon)
{
	float xCenter = icon.getLocalBounds().width / 2.f;
	float yCenter = icon.getLocalBounds().height / 2.f;
	icon.setOrigin(xCenter, yCenter);
	icon.setPosition(sf::Vector2f(m_window.getSize()) / 2.f);
}

void GameStateIntro::update()
{
	using namespace sf;
	using namespace util;
	Time now = m_introClock.getElapsedTime();
	if( now - m_fadeTick > milliseconds(50) )
	{
		switch(fadeDirection)
		{
		case In:
			{
				Uint8 a = getAlpha(m_introIcon);
				if(a < SF_COLOR_MAX) setAlpha(m_introIcon, a + 15);
				else fadeDirection = None;
				break;
			}
		case Out:
			{
				Uint8 a = getAlpha(m_introIcon);
				if(a > SF_COLOR_MIN) setAlpha(m_introIcon, a - 15);
				break;
			}
		case None:
		default: break;
		}
		m_fadeTick = now;
	}

	if(now - m_fadeOut > milliseconds(3500))
	{
		fadeDirection = Out;
		m_fadeOut = now;
	}
	if(now - m_swapIcons > milliseconds(5000))
	{
		m_introIcon.setTexture(textureManager.get("box2D.png"), true);
		centerIcon(m_introIcon);
		fadeDirection = In;
		m_swapIcons = now;
	}
}

void GameStateIntro::draw()
{
	m_window.draw(m_introIcon);
}

void GameStateIntro::handleEvents()
{
	using namespace sf;
	Time now = m_introClock.getElapsedTime();
	if(now - m_autoChange > milliseconds(9000))
	{
		m_manager.changeState(std::unique_ptr<GameState>(new GameStateMenu(m_manager)));
	}

	Event event;
	while(m_window.pollEvent(event))
	{
		if(event.type == Event::Closed || (event.type == Event::KeyPressed && (event.key.alt && event.key.code == Keyboard::F4) ))
		{
			m_window.close();
		}
		else if(event.type == Event::KeyPressed && event.key.code == Keyboard::Space)
		{
			m_manager.changeState(std::unique_ptr<GameState>(new GameStateMenu(m_manager)));
		}
	}
}
