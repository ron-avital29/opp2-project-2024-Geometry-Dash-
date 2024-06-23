#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <memory> // Required for std::unique_ptr
#include <Box2D/Box2D.h>
#include "GameObj/MovablesObj/Player.h"
#include "ButtonCommand/Button.h"
#include "Singletones/TexturesManger.h"
#include "ScreenStates/GameState.h"
#include "WorldMap.h"
//include "PauseMenu.h"
#include "GameObj/StaticObj/Static.h"

#include "CollisionHandler.h"
#include "ContactListener.h"

#include "Singletones/MusicManager.h"

class Menu;
class Controller;

class Game : public GameState
{
public:
	Game(int levelNum, Controller& controller, Menu& menuState, sf::Music& music);
	Singleton& m_resources = Singleton::instance();

	virtual void handleEvent(const sf::Event&, sf::RenderWindow&, sf::Time time);
	virtual void draw(sf::RenderWindow& window, int r, int g, int b);
	virtual void update(sf::Time);

	void setChosenPlayer(int i);
	void setState(Menu*); //are we using this?

private:
	virtual void setSwitchMusic();

	void initPlayer();
	void initWorld();
	void moveEnemy(sf::Time time);
	void handleRestart();
	std::unique_ptr<Player> m_player;

	MusicManager& m_musicHandler = MusicManager::instance();
	sf::Music& m_backgroundMusic;

	Controller& m_controller;

	sf::Vector2f m_startLocation;
	int m_level;
	int m_musicTrack;
	bool m_restartRound = false;

	std::unique_ptr<Button>m_pauseButton;
	sf::RectangleShape m_background;
	Menu* m_menuState;
	WorldMap m_map;
	
	sf::Vector2f m_prevView; //try to erase when possible and see if we even use it

	MovablesObj m_movables;
	FixedObj m_fixed;

	//--------------BOX2D-------------
	b2Vec2 m_gravity;
	std::unique_ptr<b2World> m_world;

	ContactListener m_listner;
};