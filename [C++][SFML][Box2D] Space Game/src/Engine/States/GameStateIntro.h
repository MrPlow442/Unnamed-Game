#ifndef GAMESTATEINTRO_H
#define GAMESTATEINTRO_H

#include <vector>

#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include "GameState.h"

class GameStateIntro : public GameState
{
private:
	sf::Sprite m_introIcon;
	sf::Clock m_introClock;
	sf::Time m_fadeOut;
	sf::Time m_fadeTick;
	sf::Time m_swapIcons;
	sf::Time m_autoChange;
	enum FadeDirection { None, In, Out }fadeDirection;
	void centerIcon(sf::Sprite &icon);
public:
	GameStateIntro(StateManager &manager);
	~GameStateIntro();

	void update();
	void draw();
	void handleEvents();
};
#endif // GAMESTATEINTRO_H
