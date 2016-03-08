#ifndef HEAD_MATHVECTOR
#define HEAD_MATHVECTOR
#include <SFML/System/Vector2.hpp>

extern const double pi;
struct MathVector: public sf::Vector2f
{
public:
	using sf::Vector2f::Vector2f;
	MathVector(const sf::Vector2f &v);
	MathVector(double angle);
	
	float lengthSquared(void) const;
	float length(void) const;
	MathVector normalized(void) const;
};
#endif //HEAD_MATHVECTOR
