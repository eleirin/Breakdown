#include "MathVector.h"
#include "Bullet.h"

Bullet::Bullet(MathVector pos, MathVector direction, float vitesse) :
	m_Sprite(5),
	m_Position(pos),
	m_Direction(direction),
	m_Vitesse(vitesse)
{
}

Bullet::~Bullet()
{
}

void Bullet::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
	rt.draw(m_Sprite, s);
}

void Bullet::update(float dt)
{
	m_Position += m_Direction.normalized() * m_Vitesse * dt;
	m_Sprite.setPosition(m_Position);
}

Bullet::Sprite::Sprite(int Diameter): 
	m_Circle(Diameter)
{
	m_Circle.setFillColor(sf::Color::Green); 
}

void Bullet::Sprite::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
	rt.draw(m_Circle, s);
}

void Bullet::Sprite::setPosition(MathVector xy)
{
	m_Circle.setPosition(xy);
}

