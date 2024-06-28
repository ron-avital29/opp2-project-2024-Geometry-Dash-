#pragma once

#include "GameObj/StaticObj/Static.h"

class AirJump : public Static
{
public:
	AirJump(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f position);
	virtual ~AirJump() = default;

private:
	static bool m_registerit;
};