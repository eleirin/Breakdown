/* \file SpellCard.h
 * \brief Specify the class SpellCard, and contains some templates (\todo {move them})
 */
#ifndef HEAD_SPELLCARD
#define HEAD_SPELLCARD
#include "ObjectManager.h"

/*! \brief Modular and abstract class that spawns bullet in a pattern.
 *
 * Every pattern of bullets will inherit of this class. A child of SpellCard will only have
 * two functions to instantiate:
 *   - The constructor, which will have to call SpellCard() to specify how frequently new bullets will be added
 *   - Explode(), this function will be called on the intervals specified by the constructor.
 *
 * During the explosion, the child will be only able to do three of these things:
 *   - spawn new bullets through the function spawn(), and modify said spawned bullets
 *   - \todo{Summon new SpellCards}
 *   - Modify m_Position (\todo{For now, the position of the bullet spawned through spawn is m_Position. Later, an offset parameter will change this relatively})
 *
 * \todo{As of yet, there is no way for explode to know how much time have passed since its last call. There will be a new parameter to indicate that}
 *
 * Finally, note that update is final, as we want the child to only work during the explosions. \todo{Draw is as well for now, as there is no way to update the position smoothly, but it will eventually be only override}
 * For better precision about how to create new patterns, see Pattern.h
 *
 * On internal note, this function simply create a delay queue that contains the delay to wait for the explosion _after the previous one_ (this is important, we stock delays relatively, which means that 3 explosions 0.1 seconds appart will be stocked as (0.1, 0.1, 0.1) not (0.1, 0.2, 0.3)
 */
class SpellCard: public Object
{
public:
	SpellCard(ObjectManager *ts, MathVector pos, int nb_explosion, float interval);
	SpellCard(ObjectManager *ts, MathVector pos, std::list<float> list_delay);
	virtual ~SpellCard(void);

	void update(float dt) override final;
	void draw(sf::RenderTarget &, sf::RenderStates) const override;

	template<typename U> Bullet* spawn();
	template<typename U> std::list<Bullet*> spawn(int duplicates);

	virtual void explode(int i, int max) = 0;

protected:
	MathVector m_Position; /*!< The current position of the pattern. It only effects where the bullets will be spawned and is up to representation of the one using it*/

private:
	ObjectManager *m_ToSpawn; /*!< The object manager that will create the bullets we will need*/
	const int m_MaxExplosion; /*!< The total number of explosion in the pattern*/
	int m_Number; /*!< The number of explosion that already happened*/
	std::list<float> m_ToExplode; /*!< The list of future explosion to arise*/
};

/*! \brief Creates a bullet of a certain type
 *
 * This function creates a bullet of type U using as parameter the position, how many explosions has already happened and how many will there be.
 *
 * \tparam U The type of Bullet to be spawned. 
 * Restriction:
 * 	- Must have a constructor U(MathVector, int, int)
 * 	- Must be a subclass of Bullet
 *
 * \return A pointer to the bullet that was created. It can be accessed and modified normally.
 */
template<typename U>
Bullet *SpellCard::spawn(void)
{
	Bullet *created = m_ToSpawn->add<U>(m_Position, m_Number, m_MaxExplosion);
	return created;
}

/*! \brief Spawn several bullets of a certain type.
 *
 * Similar to spawn(void), this function creates duplicates number of bullet of type U using as parameter the position, how many explosions has already happened, the number of this bullet in the spawning process, and the total number of explosion
 *
 *\tparam U The type of Bullet to be spawned. 
 * Restriction:
 * 	- Must have a constructor U(MathVector, int, int, int)
 * 	- Must be a subclass of Bullet
 *
 * \return A list of pointers to all the bullets that were created. Each can be accessed and modified normally.
 */
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
