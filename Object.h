#ifndef HEAD_OBJECT
#define HEAD_OBJECT
#include <SFML/Graphics.hpp>

class Object: public sf::Drawable
{
public:
	Object(void);
	virtual ~Object(void);
	bool dead(void);
	virtual void update(float dt) = 0;

protected:
	bool m_Dead;
};
#endif //HEAD_OBJECT
