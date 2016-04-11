/*! \file Object.cpp
 */
#include "Object.h"

AbstractObject::AbstractObject()
:
    m_Dead(false)
{
}

/*** AbstractObject ***/

/*! \brief Destructor of AbstractObject
 */
AbstractObject::~AbstractObject()
{
}

/*! \brief Updates the object
 *
 * This is a very generic function, it should be called everytime beetwen two
 * frames. The way the object will be updated depend on said objects
 */
void AbstractObject::update(
        float
        /*!< The elapsed time since last update*/)
{
}

bool AbstractObject::isDead(void)
{
    return m_Dead;
}

void AbstractObject::die(void)
{
    m_Dead = true;
}


/*** Object ***/

/*! \brief Constructor of Object
 */
Object::Object(
    float diameter, 
    /*!< The diameter of the object*/
    
    MathVector position
    /*!< The initial position of the object*/)
:
    m_Position(position),
    m_Sprite(diameter),
    m_Diameter(diameter)
{
}

/*! \brief Destructor of Object
 */
Object::~Object(void)
{
}


bool Object::isColliding(const Object &rhs
    /*!< The object to test the collision with*/)
{
    /* We use this cool trick of considering a bigger objects, and just test if
     * the center is in it (if you do not understand -> Wikipedia on collisions)
     */
    int diameter = m_Diameter + rhs.m_Diameter;
    int length_squared = MathVector(m_Position - rhs.m_Position).lengthSquared();

    return (length_squared < diameter * diameter);
}

/*! \brief Updates the object
 *
 * This function shall be called by every child after their own update calls to
 * manage internal settings such as the sprite
 */
void Object::update(
    float
    /*!< Elapsed time since last update*/)
{
    m_Sprite.setPosition(m_Position);
}

/* */
void Object::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    rt.draw(m_Sprite, s);
}

/*! \brief Says wether an object is dead
 *
 * If the object is dead but that it didn't get removed (see
 * ObjectManager::update to see why) we do not want to consider it in our own
 * update function.
 *
 * \retval true The object is dead
 * \retval false The object is still alive
 */

/*** Object::Sprite ***/

/*! \brief Constructor of Sprite
 */
Object::Sprite::Sprite(
    int Diameter
    /*!< The size in pixel of the sprite*/)
:
    m_Circle(Diameter, 50)
{
}

/*! \brief Destructor of Sprite
 */
Object::Sprite::~Sprite()
{
}

/* */
void Object::Sprite::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    rt.draw(m_Circle, s);
}

/*! \brief Set the position of the sprite
 *
 * As all positions in the world will be in their own coordinates and
 * not in pixel coordinates, we need a function to translate between the two.
 */
void Object::Sprite::setPosition(
        MathVector xy
        /*!< The position to set the sprite to*/)
{
    xy.x = float(pixel_per_meter) * xy.x;
    xy.y  = 500 - float(pixel_per_meter) * xy.y;

    m_Circle.setPosition(xy);
}
