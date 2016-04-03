#ifndef HEAD_OBJECT
#define HEAD_OBJECT
#include "MathVector.h"
#include <SFML/Graphics.hpp>

/*! \brief Type of every objects in our game
 *
 * This is the general type of every objects we will ever use. It defines the
 * function that one needs to implement and that will be called for every one of
 * them.
 * The two function to be implemented are draw and update.
 */
class AbstractObject: public sf::Drawable
{
public:
    virtual ~AbstractObject();
    virtual void update(float dt) = 0;
};

/* For now we assume spherical object*/
class Object: public AbstractObject
{
public:
    Object(float diameter, MathVector position=MathVector(0, 0));
    virtual ~Object(void);
    bool isDead(void);
    bool isColliding(const Object &rhs);
    void update(float dt) override = 0;
    void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

protected:
    struct Sprite: public sf::Drawable
    {
        Sprite(int Diameter);
        virtual ~Sprite();
        void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;
        void setPosition(MathVector xy);
        sf::CircleShape m_Circle;
    } m_Sprite;

    float m_Diameter;
    MathVector m_Position;
    bool m_Dead;
};
#endif //HEAD_OBJECT
