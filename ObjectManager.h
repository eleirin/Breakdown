/*! \file ObjectManager.h
 */
#ifndef HEAD_OBJECTMANAGER
#define HEAD_OBJECTMANAGER
#include <list>
#include <SFML/Graphics.hpp>
#include "Object.h"
#include <string>

class Interface_ObjectManager: public AbstractObject
{
};

/*! \brief A class that will manage the creation and the destructions
 * of all objects
 *
 * Note that ObjectManager is itself an AbstractObject. There need not be a
 * single instance of Object Manager, as some objects may have their owns (for
 * instance, for particule effects)
 *
 * \todo Turn m_AliveList into a vector
 */
template<typename T = AbstractObject>
class ObjectManager: public Interface_ObjectManager
{
public:
    void ObjectManager(void);
    virtual ~ObjectManager(void);
    template<typename U, typename... Args> U* add(Args&& ... args);
    void update(float dt) override;
    void draw(sf::RenderTarget &rt, sf::RenderStates s) const final;

    bool isColliding(const Object &rhs) const;
private:
    const std::string m_Name;
    std::list<T*> m_AliveList; /*!< The list of all objects created so far*/
};
typedef ObjectManager<Object> MaterialObjectManager;
typedef ObjectManager<Interface_ObjectManager> MasterManager;

#include "ObjectManager.tpp"
#endif //HEAD_OBJECTMANAGER
