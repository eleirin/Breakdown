/*! \file Object.h
 */
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

/*! \brief Type of every object that are killable or directly in game (e.g not HUB or particule
 * effects).
 *
 * For now, we assume spherical objects. Such objects all have a sprite, and can
 * die by setting their m_Dead flag to true in the update function (the ObjectManager will take care of
 * deleting them)
 */
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
    MathVector m_Position; /*!< The current position of the object*/
    bool m_Dead; /*!< Should always be false, if the object set it to true, it will be deleted*/

private:
    /*! \brief The sprite to draw the object
     *
     * A circle for now
     */
    struct Sprite: public sf::Drawable
    {
        Sprite(int Diameter);
        virtual ~Sprite();
        void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;
        void setPosition(MathVector xy);

        sf::CircleShape m_Circle; /*!< The content of the sprite*/
    } m_Sprite;

    const float m_Diameter; /*!< The diameter of the object*/
    };
#endif //HEAD_OBJECT
