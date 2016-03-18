/*! \file Bullet.cpp
 *  \brief Implements the function of Bullet*/
#include "MathVector.h"
#include "Bullet.h"

/*! \brief Constructor of Bullet
 *
 * For now the parameters are not very refined. We will change the constructor as needs goes
 */
Bullet::Bullet( MathVector pos, //!< The initial position of the bullet
                MathVector direction, //!< The initial direction in which the bullet will go
                float speed) //!< The speed of the bullet
: 
    Object(5, pos),
    m_Direction(direction.normalized()),
    m_Speed(speed)
{
}

/*! \brief Destructor of Bullet
 */
Bullet::~Bullet(void)
{
}

/* UNCOMMENTED */
void Bullet::draw(sf::RenderTarget &rt,
          sf::RenderStates s) const
{
    rt.draw(m_Sprite, s);
}

/*! \brief Update the bullet
 *
 * Simply update the position of the bullet based on its direction and speed
 */
void Bullet::update(float dt) //!< The time elapsed since last update
{
    m_Position += m_Direction * m_Speed * dt;
    Object::update(dt);
}
