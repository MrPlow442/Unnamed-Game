#ifndef GAMESTATEINGAME_H
#define GAMESTATEINGAME_H

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include <Box2D\Box2D.h>

#include "GameState.h"
#include "..\Debug\SFMLDebugDraw.h"

class GameStateIngame : public GameState
{
private:
	b2World m_physicsWorld;
	const int m_velocityIterations;
	const int m_positionIterations;

	sf::Sprite background;

	/* Debug only */
	SFMLDebugDraw m_debugDraw;
public:
	GameStateIngame(StateManager& manager);
	~GameStateIngame();

	void update();
	void draw();
	void handleEvents();
};
#endif // GAMESTATEINGAME_H