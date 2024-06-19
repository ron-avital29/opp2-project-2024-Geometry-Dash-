#pragma once
#include "AnimationData.h"
#include "Singleton.h"
#include <SFML/Graphics.hpp>


class Robot;

class Animation
{
public:
    Animation(const AnimationData& data, Direction dir, Robot& robot);

    // Set the direction; the sprite will take the relevant texture rect
    void direction(Direction dir);

    // Add more time to the elapsed time; if enough time passed, it
    // updates the sprite to show the next frame in the animations
    void update(sf::Time delta);

private:
    // Update the sprite to take the correct part of the texture,
    // based on current dir and index
    void update();

    Singleton& m_resources = Singleton::instance();
    const AnimationData& m_data;
    sf::Time m_elapsed = {};
    Direction m_dir = Direction::Right;
    int m_index = 0;
    sf::RectangleShape* m_sprite;
    Robot& m_robot;
};