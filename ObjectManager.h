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
	template<typename U, typename... Args> U* add(Args... args);
	void update(float dt) override;
	void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

private:
	std::list<Object*> m_AliveList;
};

template<typename U, typename... Args>
U* ObjectManager::add(Args... args)
{
	U *created = new U(args...);
	m_AliveList.push_front(created);
	return created;
}

#endif //HEAD_BULLETMANAGER
