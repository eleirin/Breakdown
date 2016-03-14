#ifndef HEAD_HEROIN
#define HEAD_HEROIN
#include "Object.h"
#include "Constant.h"

class Heroin: public Object
{
public:
	Heroin();
	virtual ~Heroin();
	void jump(void);
	void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;
	void update(float dt) override;
private:
	struct Sprite: public sf::Drawable
	{
		Sprite(int Diameter);
		~Sprite();
		void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;
		void setPosition(MathVector xy);
		sf::CircleShape m_Circle;
	} m_Sprite;

	float m_ForceInit;
	MathVector m_Speed;
	bool m_Jumping;
};
#endif //HEAD_HEROIN
