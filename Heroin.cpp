/*! \brief Heroin.cpp
 */
#include "Heroin.h"

/*! \brief Constructor of Heroin
 */
Heroin::Heroin():
    Object(10, MathVector(0, 0)),
    m_ForceInit(5),
    m_Speed(0, 0),
    m_Jumping(false)
{
}

/*! \brief Destructor of Heroin
 */
Heroin::~Heroin()
{
}

/*! \brief Makes the heroin jump
 *
 * \todo{As for now, this function is public and is called by the main. In time it
 * should be called by the update function.}
 * The jump cannot be modified, and the heroin will fall as though under normal
 * gravity
 */
void Heroin::jump(void)
{
    if(!m_Jumping)
    {
        m_Jumping = true;
        m_Speed.y = m_ForceInit;
    }
}

/*! \brief Updates the speed and the position of the heroin
 */
void Heroin::update(float dt)
{
    // Updates internal states based on keyboard
    if(sf::Keyboard::isKeyPressed(key_jump))
            jump();

    // Right now we fall only when we are jumping
    if(m_Jumping)
    {
        m_Speed.y -= gravity * dt;
        m_Position += m_Speed  * dt;

        /*Stop jumping if on the ground*/
        if(m_Position.y <= 0)
        {
            m_Position.y = 0;
            m_Jumping = false;
        }
    }
    Object::update(dt);
}
