/*! \brief Heroin.h
 */

#ifndef HEAD_HEROIN
#define HEAD_HEROIN
#include "Object.h"
#include "Bullet.h"
#include "Constant.h"

/*! \brief The main protagonist of this game.
 *
 * As for now, she can only jump, and not modify her jump in air. As the project
 * goes, we will see wether she should be able to control the magnitude of her
 * jump, of the way she runs.
 * \todo Make her run
 * \todo Make her die when colliding with a bullet
 * \todo Encapsulate the mechanics (jumping, double jump etc...) In
 * substructures
 */
class Heroin: public Object
{
public:
    Heroin(const BulletManager& all_bullets);
    virtual ~Heroin();
    void update(float dt) override;

private:
    void jump(void);

    const BulletManager &m_AllBullets; /*!< The bullets to die to*/
    const float m_ForceInit; /*!< How strong are her jump*/
    MathVector m_Speed; /*!< Her current vertical speed*/
    bool m_Jumping; /*!< Wether she is currently jumping or not*/
};
#endif //HEAD_HEROIN
