#include "Heroin.h"

Heroin::Heroin():
	Object(MathVector(0, 0)),
	m_Sprite(20),
	m_ForceInit(5),
	m_Speed(0, 0),
	m_Jumping(false)
{
}

Heroin::~Heroin()
{
}

void Heroin::jump(void)
{
	if(!m_Jumping)
	{
		m_Jumping = true;
		m_Speed.y = m_ForceInit;
	}
}

void Heroin::update(float dt)
{
	if(m_Jumping)
	{
		m_Speed.y -= gravity * dt;
		m_Position += m_Speed  * float(pixel_per_meter) * dt;
		if(m_Position.y <= 0)
		{
			m_Position.y = 0;
			m_Jumping = false;
		}
	}
	m_Sprite.setPosition(m_Position);
}

void Heroin::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
	m_Sprite.draw(rt, s);
}

Heroin::Sprite::Sprite(int Diameter): 
	m_Circle(Diameter)
{
	m_Circle.setFillColor(sf::Color::Green); 
}

Heroin::Sprite::~Sprite()
{
}

 void Heroin::Sprite::setPosition(MathVector xy)
{
	m_Circle.setPosition(xy);
}

void Heroin::Sprite::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
	rt.draw(m_Circle, s);
}
