#include "MathVector.h"
#include "Bullet.h"

/*! \brief Constructor of Bullet
 *
 * For now the parameters are not very refined. We will change the constructor as needs goes
 */
Bullet::Bullet( MathVector pos /*!< The initial position of the bullet*/,
	        MathVector direction /*!< The initial direction in which the bullet will go*/,
	        float speed /*!< The speed of the bullet*/) :
	Object(pos),
	m_Sprite(5),
	m_Direction(direction),
	m_Vitesse(vitesse)
{
}

Bullet::~Bullet(void)
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

Bullet::Sprite::~Sprite()
{
}

void Bullet::Sprite::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
	rt.draw(m_Circle, s);
}

void Bullet::Sprite::setPosition(MathVector xy)
{
	m_Circle.setPosition(xy);
}

