#include "Bullet.h"
#include "SpellCard.h"

/*! \brief Construct a spell card that will explode every delay specified by list_delay
 *
 *
 * \param ts The object manager in which we will spawn the bullet
 * \param pos The original position of the pattern
 * \param list_delay 
 */
SpellCard::SpellCard(MathVector pos, ObjectManager *ts, std::list<float> list_delay):
    Object(0, pos),
    m_ToSpawn(ts),
    m_MaxExplosion(list_delay.size()),
    m_Number(0),
    m_ToExplode(list_delay)
{
}

/*! \brief Construct a spell card that will explode every interval second
 *
 * \param ts The object manager in which we will spawn the bullet
 * \param pos The original position of the pattern
 * \param nb_explosion The total number of explosion that will happen
 * \param interval The interval between two explosions
 */
SpellCard::SpellCard(MathVector pos, ObjectManager *ts, int nb_explosion, float interval):
    SpellCard(pos, ts, std::list<float>(nb_explosion, interval))
{
}

SpellCard::~SpellCard(void)
{
}


void SpellCard::update(float dt)
{
    if(m_ToExplode.empty())
    {
        m_Dead = true;
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

void SpellCard::draw(sf::RenderTarget &, sf::RenderStates) const
{
}
