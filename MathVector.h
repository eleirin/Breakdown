/*! \file MathVector.h
 */
#ifndef HEAD_MATHVECTOR
#define HEAD_MATHVECTOR
#include <SFML/System/Vector2.hpp>
#include "Constant.h"

/*! \brief An augmented class of sf::Vector
 *
 * This version allows us to have many more useful functions such as length,
 * normalized, in time we will have dot products and many more
 *
 * \note{All functions are const, modification will only happen through direct
 * copy affectation. This is to keep a mathematical scheme and expected
 * behaviours.}
 * \note{All coordinates will be in the world coordinate and not in pixel, there
 * will be one function to transcribe between the two}
 */
struct MathVector: public sf::Vector2f
{
public:
    using sf::Vector2f::Vector2f;
    MathVector(const sf::Vector2f &v = sf::Vector2f(0, 0));
    MathVector(double angle);
    virtual ~MathVector(void);
    
    float lengthSquared(void) const;
    float length(void) const;
    MathVector normalized(void) const;
};

#endif //HEAD_MATHVECTOR
