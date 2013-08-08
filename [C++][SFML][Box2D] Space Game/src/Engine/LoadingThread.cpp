#include "LoadingThread.h"

//Resource Managers
#include "Resource\FontManager.h"
//Debug
#include "DBG\dbgmsg.h"


LoadingThread loadingThread;

LoadingThread::LoadingThread() : 
	m_end(false),
	loadingText("Now Loading", fontManager.get("LeagueGothic-Regular.otf"))
{
	DBGMSGR("Constructing " << typeid(*this).name());
	loadingText.setColor(sf::Color::White);
}

LoadingThread::~LoadingThread()
{
	DBGMSGR("Destructing " << typeid(*this).name());
	if(m_thread.joinable())
		m_thread.join();
}


void LoadingThread::displayLoading( sf::RenderWindow& window )
{
	window.setActive(true);
	while(window.isOpen() && !m_end)
	{
		window.clear(sf::Color::Black);
		window.draw(loadingText);
		window.display();
	}
	window.setActive(false); 
}


void LoadingThread::Start( sf::RenderWindow &window )
{
	DBGMSGR("Creating new thread");
	window.setActive(false);
	m_thread =  std::thread(&LoadingThread::displayLoading, this, std::ref(window));
}

void LoadingThread::End()
{
	m_end = true;
	if(m_thread.joinable())
		m_thread.join();
	DBGMSGR("Thread joined");
}
