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
    float m_ForceInit;
    MathVector m_Speed;
    bool m_Jumping;
};
#endif //HEAD_HEROIN
