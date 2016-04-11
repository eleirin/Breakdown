/*! \brief Detects if two object are colliding
 *
 * This function is specific to spherical objects, remember to change it when
 * implementing other types of objects
 */

template <typename T>
bool Object::isColliding(
        const ObjectManager<T> &rhs
        /*!< */)
{
    return rhs.isColliding(*this);
} 
