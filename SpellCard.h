#ifndef HEAD_SPELLCARD
#define HEAD_SPELLCARD
#include "ObjectManager.h"

class SpellCard: public Object
{
public:
	SpellCard(ObjectManager *ts, MathVector pos, int nb_explosion, float interval);
	SpellCard(ObjectManager *ts, MathVector pos, std::list<float> list_delay);
	virtual ~SpellCard(void);

	void update(float dt) override final;
	void draw(sf::RenderTarget &, sf::RenderStates) const override final;

	template<typename U> Bullet* spawn();
	template<typename U> std::list<Bullet*> spawn(int duplicates);

	virtual void explode(int i, int max) = 0;

private:
	ObjectManager *m_ToSpawn;
	const int m_MaxExplosion;
	int m_Number;
	std::list<float> m_ToExplode; 
	MathVector m_Position;
};

template<typename U>
Bullet *SpellCard::spawn(void)
{
	Bullet *created = m_ToSpawn->add<U>(m_Position, m_Number, m_MaxExplosion);
	return created;
}

template<typename U>
std::list<Bullet *> SpellCard::spawn(int duplicates)
{
	std::list<Bullet *> created;

	for(int i = 0; i < duplicates; i++)
	{
		created.push_front(m_ToSpawn->add<U>(m_Position, m_Number, i, m_MaxExplosion));
	}

	return created;
}

#endif //HEAD_SPELLCARD
