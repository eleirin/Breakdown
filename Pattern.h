#ifndef HEAD_PATTERN
#define HEAD_PATTERN
#include <cmath>
#include "ObjectManager.h"
#include "Bullet.h"
#include "SpellCard.h"

class SpiralBullet: public Bullet
{
public:
	SpiralBullet(MathVector pos, int i, int j, int max):
		Bullet(pos, MathVector((i * 2 * pi / max) + j * pi / 2), 100)
	{
	}
	virtual ~SpiralBullet()
	{
	}
};

class Spiral : public SpellCard
{
public:
	Spiral(MathVector pos, ObjectManager *ts):
		SpellCard(pos, ts, 25, 0.1)
	{
	}

	virtual ~Spiral()
	{
	}

	void explode(int, int)
	{
		spawn<SpiralBullet>(4);
	}
};

#endif //HEAD_PATTERN
