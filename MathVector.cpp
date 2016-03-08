#include <cmath>
#include <cfloat>
#include <SFML/System/Vector2.hpp>
#include "MathVector.h"

const double pi = 3.14159265358979323846;
MathVector::MathVector(const sf::Vector2f &v):
	sf::Vector2f(v)
{
}

MathVector::MathVector(double angle):
	sf::Vector2f(cos(angle), sin(angle))
{
}

float MathVector::lengthSquared(void) const
{
	return x*x + y*y;
}

float MathVector::length(void) const
{
	return sqrt(lengthSquared());
}

MathVector MathVector::normalized(void) const
{
	float len = length();

	if(len < DBL_EPSILON)
		return (*this);
	else
		return (*this)/length();
}
