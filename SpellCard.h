/* \file SpellCard.h
 */
#ifndef HEAD_SPELLCARD
#define HEAD_SPELLCARD
#include "ObjectManager.h"

/*! \brief Modular and abstract class that spawns bullet in a pattern.
 *
 * This function basically call the explode function on specified time.
 * Every pattern of bullets will inherit of this class. A child of SpellCard will only have
 * two functions to instantiate:
 *   - The constructor, which will have to call SpellCard() to specify how frequently new bullets will be added
 *   - Explode, this function will be called on the intervals specified by the constructor.
 *
 * See the explode and spawn function to know what a child can do on those
 * explosions.
 *
 * Note also that update is final, as we want the child to only do jobs during the explosions.
 * For better precision about how to create new patterns, see Pattern.h
 *
 * On internal note, this function simply create a delay queue that contains the delay to wait for the explosion _after the previous one_ (\note{this is important, we stock delays relatively, which means that 3 explosions 0.1 seconds appart will be stocked as (0.1, 0.1, 0.1) not (0.1, 0.2, 0.3)})
 * 
 * \todo Add a Summon function to summon Spellcards within spellcards
 * \todo Turn draw into a non-final function
 */
 
class SpellCard: public Object
{
public:
    SpellCard(MathVector pos, ObjectManager<Bullet> &ts, std::list<float> list_delay);
    SpellCard(MathVector pos, ObjectManager<Bullet> &ts, int nb_explosion, float interval);
    virtual ~SpellCard(void);

    void update(float dt) final;
    void draw(sf::RenderTarget &, sf::RenderStates) const override;

    template<typename U> Bullet* spawn(void) const;
    template<typename U> std::list<Bullet*> spawn(int duplicates) const;

    virtual void explode(int i, int max) const = 0;

private:
    const int m_MaxExplosion; /*!< The total number of explosion in the pattern*/
    BulletManager &m_ToSpawn; /*!< The object manager that will create the bullets we will need*/
    int m_Number; /*!< The number of explosion that already happened*/
    std::list<float> m_ToExplode; /*!< The list of future explosion to arise*/
};

#include "SpellCard.tpp"
#endif //HEAD_SPELLCARD
