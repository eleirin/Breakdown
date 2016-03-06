#include "Bullet.h"
#include "SpellCard.h"

SpellCard::SpellCard(ObjectManager *ts, MathVector pos, int nb_explosion, float interval):
m_ToSpawn(ts),
	m_MaxExplosion(nb_explosion),
	m_Number(0),
	m_ToExplode(nb_explosion, interval),
	m_Position(pos)
{
}

SpellCard::SpellCard(ObjectManager *ts, MathVector pos, std::list<float> list_delay):
	m_ToSpawn(ts),
	m_MaxExplosion(list_delay.size()),
	m_Number(0),
	m_ToExplode(list_delay),
	m_Position(pos)
{
}

SpellCard::~SpellCard()
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
