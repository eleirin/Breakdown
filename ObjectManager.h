#ifndef HEAD_BULLETMANAGER
#define HEAD_BULLETMANAGER
#define MAX_BULLETS 1000
#include <list>
#include <SFML/Graphics.hpp>
#include "Object.h"

enum Layers
{
	BULLETS = 0,
	COUNT_LAYERS
};

class ObjectManager: public Object
{
public:
	ObjectManager(void);
	~ObjectManager(void);
	template<typename U, typename... Args> U* add(Args... args);
	void update(float dt) override;
	void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

private:
	std::list<Object*> m_AliveList;
};

#include "ObjectManager.tpp"
#endif //HEAD_BULLETMANAGER
