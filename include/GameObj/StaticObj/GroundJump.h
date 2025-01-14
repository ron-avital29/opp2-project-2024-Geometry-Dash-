#pragma once

#include "GameObj/StaticObj/Static.h"

class GroundJump : public Static
{
public:
	GroundJump(World& world, sf::Color color, sf::Vector2f position);
	virtual ~GroundJump() = default;
private:
	static bool m_registerIt;
	static bool m_registerItUp;
};