#ifndef HEAD_BULLETS
#define HEAD_BULLETS
#include <SFML/Graphics.hpp>
#include "Object.h"
#include "MathVector.h"

class Bullet: public Object
{
public:
	Bullet(MathVector pos, MathVector direction, float vitesse);
	virtual ~Bullet();
	void update(float dt) override;
	void draw(sf::RenderTarget &rt, sf::RenderStates s) const override final;

private:
	struct Sprite: public sf::Drawable
	{
		Sprite(int Diameter);
		void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;
		void setPosition(MathVector xy);
		sf::CircleShape m_Circle;
	} m_Sprite;

	MathVector m_Position;
	MathVector m_Direction;
	float m_Vitesse;
};


#endif //HEAD_BULLETS
