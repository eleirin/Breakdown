#include "Object.h"

AbstractObject::~AbstractObject()
{
}

Object::Object(float diameter, MathVector position):
    m_Sprite(diameter),
    m_Position(position),
    m_Dead(false)
{
}

/*! \brief Update the object
 *
 * This fonction shall be called by every objects and will be called between 
 * every frames
 */
void AbstractObject::update(float) //!< The elapsed time since last update
{
}

Object::~Object(void)
{
}

bool Object::isColliding(const Object &rhs)
{
    int diameter = m_Diameter + rhs.m_Diameter;
    int length_squared = MathVector(m_Position - rhs.m_Position).lengthSquared();

    return length_squared < diameter * diameter;
}

void Object::update(float)
{
    m_Sprite.setPosition(m_Position);
}

bool Object::isDead(void)
{
    return m_Dead;
}

Object::Sprite::Sprite(int Diameter):
    m_Circle(Diameter, 50)
{
}

Object::Sprite::~Sprite()
{
}

void Object::Sprite::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    rt.draw(m_Circle, s);
}

void Object::Sprite::setPosition(MathVector xy)
{
    xy  = MathVector(0, 600) - float(pixel_per_meter) * xy;
    m_Circle.setPosition(xy);
}
