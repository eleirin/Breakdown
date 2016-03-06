#include "Object.h"

Object::Object(void):
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

