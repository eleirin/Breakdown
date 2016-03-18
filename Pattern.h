#ifndef HEAD_PATTERN
#define HEAD_PATTERN
#include <cmath>
#include "Constant.h"
#include "ObjectManager.h"
#include "Bullet.h"
#include "SpellCard.h"

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

    void explode(int, int) override
    {
        spawn<SpiralBullet>(4);
    }


};

#endif //HEAD_PATTERN
