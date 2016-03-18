#include "Bullet.h"
#include "ObjectManager.h"

ObjectManager::~ObjectManager(void)
{
    for(auto &i: m_AliveList)
    {
        delete i;
    }
}

void ObjectManager::update(float dt)
{
    std::list<std::list<Object *>::iterator> DeadList;

    for(auto i = m_AliveList.begin(); i != m_AliveList.end(); i++)
    {
        (*i)->update(dt);

        if((*i)->isDead())
        {
            DeadList.push_front(i);
        }
    }
    for(auto &i : DeadList)
    {
        m_AliveList.erase(i);
        delete (*i);
    }
}

void ObjectManager::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    for(auto &i: m_AliveList)
    {
        rt.draw(*i, s);
    }
}
