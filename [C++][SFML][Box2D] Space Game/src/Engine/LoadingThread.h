#ifndef LOADINGTHREAD_H
#define LOADINGTHREAD_H

#include <thread>
#include <functional>

#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

class LoadingThread;

extern LoadingThread loadingThread;

class LoadingThread
{
private:
	std::thread m_thread;
	bool m_end;
	sf::Text loadingText;
	void displayLoading(sf::RenderWindow& window);
public:
	LoadingThread();
	~LoadingThread();
	void Start(sf::RenderWindow &window);
	void End();
};
#endif // LOADINGTHREAD_H
