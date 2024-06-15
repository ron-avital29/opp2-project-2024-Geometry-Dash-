#include "Player.h"
#include <iostream>

Player::Player(std::unique_ptr<b2World>& world, sf::Texture& texture, sf::Color color, sf::Vector2f pos)
	: Movable(world, texture, color, pos), m_startLocation(pos), m_bullets(0), m_isJumping(false), m_jumpKeyPressedLastFrame(false)
{
	setTexture(m_resources.getPlayerTexture(0));	//give here the right int		
}

Player::~Player()
{
}

void Player::move(sf::Time time)
{
	b2Vec2 boxPos = getBox()->GetPosition();

	auto dt = time.asSeconds();

	if (m_spiked)
	{
		m_spiked = false;
		boxPos.x = getStartLocation().x/30;
		boxPos.y = getStartLocation().y/30;
		getBox()->SetTransform(boxPos, true);

	}

	getBox()->SetTransform(boxPos + b2Vec2(VELOCITY * dt, 0.0f), getBox()->GetAngle());
	setPosition(sf::Vector2f(boxPos.x * 30, boxPos.y * 30));



	//m_angle = m_box->GetAngle()+ 90.0f; -ask ron (i will try to make it so that when jumping will the player will rotate. but anyway this needs to go)s
	//all of the options for moving in constant speed:
	//getBox()->SetLinearVelocity(b2Vec2(5, getBox()->GetLinearVelocity().y));
	//getBox()->ApplyForce(b2Vec2(50, 0), getBox()->GetWorldCenter(), true);
	//getBox()->ApplyLinearImpulse(b2Vec2(0.13f, 0), getBox()->GetWorldCenter(), true);

}


void Player::setChosenPlayer(int i)
{
	setTexture(m_resources.getPlayerTexture(i));
}

void Player::setBox(std::unique_ptr<b2World>& world)
{
	initBox(world, b2_dynamicBody);
}

void Player::startJump()
{
	if (!m_isJumping)
	{
		m_isJumping = true;
		b2Vec2 vel = b2Vec2(getBox()->GetLinearVelocity().x+0.6f, -15);
		//getBox()->ApplyLinearImpulseToCenter(vel, true);
		getBox()->SetLinearVelocity(vel);
	}
}

void Player::moveRight()
{
	//move X acording to player movement
	//getBox()->SetLinearVelocity(b2Vec2(6.7f, getBox()->GetLinearVelocity().y));
}

void Player::setStratLocation(sf::Vector2f pos)	//we dont use it for now...
{
	m_startLocation = pos;
}

sf::Vector2f Player::getStartLocation() const
{
	return m_startLocation;
}

void Player::setSpiked(bool state)
{
	m_spiked = state;
}

bool Player::getSpiked() const
{
	return m_spiked;
}

void Player::setJumping(bool state)
{
	m_isJumping = state;
}

bool Player::isJumping() const
{
	return m_isJumping;
}
