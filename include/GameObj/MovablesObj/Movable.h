#pragma once

#include "GameObj/Object.h"

class Movable : public Object
{
public:
	Movable(std::unique_ptr<b2World>& world, sf::Color color, sf::Vector2f pos, sf::Vector2f boxSize);
	virtual void makeVirtural() = 0;
	virtual void move(sf::Time time) = 0;
	virtual ~Movable();

	virtual bool isDestroyState() const;

	void initBox(std::unique_ptr<b2World>& world, b2BodyType bodyType, sf::Vector2f boxSize);	//private?
	void createFixture(b2FixtureDef* fixtureDef);
	b2Vec2 getBoxPosition() const;
	void setTransform(const b2Vec2& position);
	b2Vec2 getLinearVelocity() const;
	void setLinearVelocity(const b2Vec2& vel);
	float getAngle() const;
	b2Vec2 getBPosition() const;
	void setMyGravity(float g);

	void setDestroyed(bool state);
private:
	b2Body* m_box;
	b2BodyDef m_bodyDef;
	bool m_toDestroy;
};