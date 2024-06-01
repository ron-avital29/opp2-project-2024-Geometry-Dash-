#include "Game.h"
#include <iostream>

Game::Game()
	//: m_pauseButton(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(1))
{
	m_pauseButton.push_back(Button(sf::Vector2f(WINDOW_X * 157 / 160, WINDOW_Y / 30), sf::Vector2f(WINDOW_X / 64, WINDOW_X / 64), RETURN, &m_cir, &m_resources.getBackButtonTexture(2)));
	m_background.setSize(sf::Vector2f(WINDOW_X, WINDOW_Y));
	m_background.setTexture(&m_resources.getMenuBackground());
}

GameState* Game::handleEvent(const sf::Event& event, sf::RenderWindow&window)
{
	switch (event.type)
	{
	case sf::Event::MouseButtonPressed:
		if (m_pauseButton[0].getGlobalBound().contains(event.mouseButton.x, event.mouseButton.y)) //not pause button!!!!!
		{
			return m_menuState;
		}
		break;
	}
	return nullptr;
}

void Game::draw(sf::RenderWindow& window)
{
	window.clear();
	window.draw(m_background);
	m_pauseButton[0].draw(window);
}

void Game::setState(Menu* menu)
{
	m_menuState = menu;
}
