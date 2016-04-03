/*! \file ObjectManager.tpp
 */

/*! \brief Spawns a new object
 *
 * This function will be used to create an object and store it in the
 * ObjectManager
 *
 * \return A pointer to the created object
 */
template<
    typename U
    /*!< The type of the object to create. It may be restricted by statiscally
     * calling the result pointer*/, 
    
    typename... Args
    /*The list of all the type of the arguments to give to the constructor of U*/>
U* ObjectManager::add(
    Args... args
    /*!< The list of the argument to give*/)
{
    U *created = new U(args...);
    m_AliveList.push_front(created);
    return created;
}

