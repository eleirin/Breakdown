/*! \file Bullet.h
 */
#ifndef HEAD_BULLETS
#define HEAD_BULLETS
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "MathVector.h"

/*! \brief General class of bullets
 *
 * This class is not yet abstract, and should be turned into one as more bullet
 * types thrive.
 * 
 * Right now, a bullet is only about position, direction and speed but that
 * should change as needs go
 */
class Bullet: public Object
{
public:
    Bullet(MathVector pos, MathVector direction, float speed);
    virtual ~Bullet(void);
    void update(float dt) override;

private:
    MathVector m_Direction; /*!< The direction of the bullet \note{Magnitude does _not_ matter}*/
    float m_Speed; /*!< The speed of the bullet*/
};


#endif //HEAD_BULLETS
