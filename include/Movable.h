#pragma once

#include "Object.h"

class Movable : public Object
{
public:
	Movable(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos);
	virtual void makeVirtural() = 0;
	virtual ~Movable() = default;
	//virtual void move() = 0;

	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType);	//private?
	void createFixture(b2FixtureDef* fixtureDef);
	b2Vec2 getBoxPosition();
private:
	b2Body* m_box;
};