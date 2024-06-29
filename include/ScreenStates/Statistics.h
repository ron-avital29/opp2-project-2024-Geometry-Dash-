#pragma once

#include "SFML/Graphics.hpp"
#include "ScreenStates/GameState.h"
#include "Singletones/GlobalConsts.h"
#include "Singletones/TexturesManger.h"
#include "ButtonCommand/NextStateCommand.h"
#include "ButtonCommand/Button.h"

class Controller;
class Game;

class Statistics : public GameState
{
public:
    Statistics(Controller& controller, Game& game);
    virtual void handleEvent(const sf::Event&, sf::RenderWindow&);
    virtual void update(sf::Time) {};
    virtual void draw(sf::RenderWindow&, int, int, int);
    virtual void switchMusic() {};
    virtual ~Statistics() = default;

    void updatePlayerStat(PlayerStats stat, int amount);
    void updateGameStat(GameStats stat, int amount);
    int getGameStat(GameStats stat) const;
    int getPlayerStat(PlayerStats stat) const;
private:
    void setBackgrounds();
    TexturesManger& m_resources = TexturesManger::instance();
    sf::RectangleShape m_background;
    sf::RectangleShape m_statsBackground;
    sf::Text m_stats;
    Button m_button;
    Controller& m_controller;
    Game& m_game;

    std::vector<int> m_gameStats;
    std::vector<int> m_playerStats;
};
