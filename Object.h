#ifndef HEAD_OBJECT
#define HEAD_OBJECT
#include "MathVector.h"
#include <SFML/Graphics.hpp>

class Object: public sf::Drawable
{
public:
	Object(MathVector position=MathVector(0, 0));
	virtual ~Object(void);
	bool dead(void);
	virtual void update(float dt) = 0;

protected:
	MathVector m_Position;
	bool m_Dead;
};
#endif //HEAD_OBJECT
