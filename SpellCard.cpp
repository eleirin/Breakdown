/*! \file SpellCard.cpp
 */
#include "Bullet.h"
#include "SpellCard.h"

/*! \brief Construct a spell card that will explode every delay specified by list_delay
 *
 *
 */
SpellCard::SpellCard(
    MathVector pos,
    /*!< The original position of the pattern */

    BulletManager &ts,
    /*!< The object manager in which we will spawn the bullet*/
    
    std::list<float> list_delay
    /*!< The list of the delays to implement*/):
    Object(0, pos),
    m_MaxExplosion(list_delay.size()),
    m_ToSpawn(ts),
    m_Number(0),
    m_ToExplode(list_delay)
{
}

/*! \brief Construct a spell card that will explode every interval second
 *
 */
SpellCard::SpellCard(MathVector pos, BulletManager &ts, int nb_explosion, float interval):
    SpellCard(pos, ts, std::list<float>(nb_explosion, interval))
{
}

/*! \brief Destructor of SpellCard
 */
SpellCard::~SpellCard(void)
{
}


/*! \brief Call explode if the delay is passed
 */
void SpellCard::update(
        float dt
        /*!< The elapsed time since last call*/)
{
    //Nothing to be done -> Die
    if(m_ToExplode.empty())
    {
        die();
        return;
    }

    m_ToExplode.front() -= dt;
    if(m_ToExplode.front() <= 0)
    {
        m_ToExplode.pop_front();
        explode(m_Number, m_MaxExplosion);
        m_Number++;
    }
}

/*! \brief The function to be called every specified time
 *
 * This function  
 * During the explosion, the child will be only able to do those things :
 *   - spawn new bullets through the function spawn(), and modify said spawned bullets
 *   - Modify m_Position
 *
 * \todo For now, the position of the bullet spawned through spawn is m_Position. Add an offset parameter to change this relatively
 * \todo As of yet, there is no way for explode to know how much time have passed since its last call. Add a new parameter to indicate that
 */
void SpellCard::explode(int, int) const
{

}

/* No drawing allowed as for now
 */
void SpellCard::draw(sf::RenderTarget &, sf::RenderStates) const
{
}
