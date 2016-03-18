/*! \brief Heroin.cpp
 *
 * Implements the function of heroin
 */
#include "Heroin.h"

Heroin::Heroin():
    Object(10, MathVector(0, 0)),
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
        m_Position += m_Speed  * dt;
        if(m_Position.y <= 0)
        {
            m_Position.y = 0;
            m_Jumping = false;
        }
    }
    Object::update(dt);
}

void Heroin::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    m_Sprite.draw(rt, s);
}

