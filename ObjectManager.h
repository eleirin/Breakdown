/*! \file ObjectManager.h
 */
#ifndef HEAD_BULLETMANAGER
#define HEAD_BULLETMANAGER
#include <list>
#include <SFML/Graphics.hpp>
#include "Object.h"

/*! \brief A class that will manage the creation and the destructions
 * of all objects
 *
 * Note that ObjectManager is itself an AbstractObject. There need not be a
 * single instance of Object Manager, as some objects may have their owns (for
 * instance, for particule effects)
 */
class ObjectManager: public AbstractObject
{
public:
    virtual ~ObjectManager(void);
    template<typename U, typename... Args> U* add(Args... args);
    void update(float dt) override;
    void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

private:
    std::list<Object*> m_AliveList; /*!< The list of all objects created so far*/
};

#include "ObjectManager.tpp"
#endif //HEAD_BULLETMANAGER
