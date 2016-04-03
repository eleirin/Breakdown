/*! \file Pattern.h
 *
 * Contains a list of all the pattern that will be created.
 * A pattern will be always created the same way:
 *   - The constructor specifies how many explosions will happen and when
 *   - The explode function will state how many bullets should be created and of
 *     what type. It may modify the resulting bullet, yet that should be only
 *     used with parcimony since most of the work will be done in the
 *     constructor of the Bullet created
 *   - Subclasses that specialize the bullets that will be created. All bullets
 *     will have constructor with either pos, i and max or pos, i, j and max as
 *     parameters. They will change their position and velocity according to
 *     when they were created
 */
#ifndef HEAD_PATTERN
#define HEAD_PATTERN
#include <cmath>
#include "Constant.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "SpellCard.h"

/*! \brief A pattern that spawns bullet in a four-ways branched spiral
 */
class Spiral : public SpellCard
{
public:
    class SpiralBullet: public Bullet
    {
    public:
        SpiralBullet(MathVector pos, int i, int j, int max):
            Bullet(pos, MathVector((i * 2 * pi / max) + j * pi / 2), 2)
        {
        }
        virtual ~SpiralBullet()
        {
        }
    };

    Spiral(MathVector pos, ObjectManager *ts):
        SpellCard(pos, ts, 25, 0.1)
    {
    }

    virtual ~Spiral()
    {
    }

    void explode(int, int) const override
    {
        spawn<SpiralBullet>(4);
    }
};

#endif //HEAD_PATTERN
