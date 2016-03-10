#include "Bullet.h"
#include "SpellCard.h"

SpellCard::SpellCard(MathVector pos, ObjectManager *ts, std::list<float> list_delay):
	m_ToSpawn(ts),
	m_MaxExplosion(list_delay.size()),
	m_Number(0),
	m_ToExplode(list_delay),
	m_Position(pos)
{
}

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
