#include "GameEngine.h"

GameEngine::GameEngine( sf::VideoMode mode, const sf::String& title, bool fullscreen, const sf::ContextSettings& settings /*= sf::ContextSettings()*/ )
	:  m_window(mode, title, (fullscreen ? sf::Style::Fullscreen : sf::Style::Default), settings), m_stateManager(m_window)
{
	m_window.setVerticalSyncEnabled(true);
}

void GameEngine::run()
{
	m_stateManager.changeState( std::unique_ptr<GameState>(new GameStateIntro(m_stateManager)));
	while(m_window.isOpen())
	{
		m_stateManager.handleEvents();
		m_stateManager.update();
		m_stateManager.draw();
		m_stateManager.cleanup();
	}
}
