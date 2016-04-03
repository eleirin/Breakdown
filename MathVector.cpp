/*! \file MathVector.cpp
 */
#include <cmath>
#include <cfloat>
#include <SFML/System/Vector2.hpp>
#include "MathVector.h"


/*! \brief Conversion constructor of MathVector from sf::Vector2f
 */
MathVector::MathVector(
    const sf::Vector2f &v
    /*!< The vector to copy from*/)
:
    sf::Vector2f(v)
{
}

/*! \brief Create a vector from an angle
 *
 * The vector will point in the direction of the angle, and be of unary length
 */
MathVector::MathVector(
        double angle
        /*!< The angle in radiant*/)
:
    sf::Vector2f(cos(angle), sin(angle))
{
}

/*! \brief Destructor of MathVector
 */
MathVector::~MathVector(void)
{
}

/*! \brief The squared length of the vector
 *
 * This function will be used in order to compare two distances since the square
 * function is an increasing one
 *
 * \return The length of the MathVector, squared
 */
float MathVector::lengthSquared(void) const
{
    return x*x + y*y;
}

/*! \brief The length of the vector
 *
 * This function will be used in plenty of case, to cap the velocity of a
 * direction, for instance
 *
 * \return The length of the MathVector
 */
float MathVector::length(void) const
{
    return sqrt(lengthSquared());
}

/*! \brief The unit vector that is pointing in the same direction
 *
 * \note{This function is const, so it will only create a vector and return it,
 * not modify the class itself}
 * \note{If the length of the vector is to small, no scaling will be applied as
 * that would result in NaN behaviours}
 *
 * \return The normalized version of the vector
 */
MathVector MathVector::normalized(void) const
{
    float len = length();

    if(len < DBL_EPSILON)
        return (*this);
    else
        return (*this)/length();
}
