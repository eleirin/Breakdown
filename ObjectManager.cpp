/*! \file ObjectManager.cpp
 */
#include "ObjectManager.h"

/*! \brief Destructor of ObjectManager
 */
ObjectManager::~ObjectManager(void)
{
    for(auto &i: m_AliveList)
    {
        delete i;
    }
}

/*! \brief Update all objects that were created by this ObjectManager
 *
 * It is to be noted that the function operates in two steps, first it updates
 * all objects, then it deletes the dead ones.
 * This is because first, we do not want to operate on memory and update at the
 * same time, as some objects might point to an indice that is wrong in some
 * functions and second because it is safer to have all the objects update in
 * the same environment, and not have them modify the environment to the other
 * \todo Further encourage two steps decomposition by having a pre-update
 * function?
 */
void ObjectManager::update(
        float dt
        /*!< Time elapsed since last call of update*/)
{
    /* We will update all the object and stock the dead one in dead list, then
     * delete all objects of the dead list
     */
    std::list<std::list<Object *>::iterator> deadList;

    //First itteration: Update all objects
    for(auto i = m_AliveList.begin(); i != m_AliveList.end(); i++)
    {
        (*i)->update(dt);

        if((*i)->isDead())
        {
            deadList.push_front(i);
        }
    }

    // Erase all dead objects
    for(auto &i : deadList)
    {
        m_AliveList.erase(i);
        delete (*i);
    }
}

/*! \brief Draw all the objects that were created by this ObjectManager
 */
void ObjectManager::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    for(auto &i: m_AliveList)
    {
        rt.draw(*i, s);
    }
}
