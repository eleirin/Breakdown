#include "Object.h"

Object::Object(MathVector position):
	m_Position(position),
	m_Dead(false)
{
}

Object::~Object(void)
{
}

bool Object::dead(void)
{
	return false;
}

