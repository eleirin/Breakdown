/* \file FunctionLine.h
 */

#ifndef HEAD_FUNCTIONLINE
#define HEAD_FUNCTIONLINE
#include <SFML/Graphics.hpp>
#include <functional>
#include "MathVector.h"

/* \brief A class that will draw a parametric function from [0, 1] to R2
 *
 * This class takes as parameter a function and will draw it every time. As in
 * Bezier, the function draw will compute the values everytime because there is
 * no way to say if the function have changed or not.
 * Indeed, even though if the function were constant, there is still the magic
 * of capture lingering around.
 * If you do not plan on modifying the function simply cast this line to
 * a VertexArray to save on efficiency.
 *
 * As of yet the colors of the curve are interpolated in RGB and recalculated
 * everytime
 *
 * \todo Do not recompute the interpolation everytime
 * \todo Turn FunctionLine into a movable object
 * \todo Add offset options and features to allow the user to use functions over
 * different sets
 */
class FunctionLine: public sf::Drawable
{
public:
    FunctionLine(const std::function<MathVector(float)> &f, int steps = 50, sf::Color begin = sf::Color::Magenta, sf::Color end = sf::Color::Cyan);
    virtual ~FunctionLine();

    operator sf::VertexArray(void) const;
    virtual void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

protected:
    sf::Color m_Begin; /*!< The color at the begining of the curve*/
    sf::Color m_End; /*!< The color at the end of the curve*/
private:
    const std::function<MathVector(float)> &m_Fun; /*!< Reference to the function to draw. It is a reference because multiple cast in a row may not yield to the same result (capture)*/
    const int m_Steps; /*!< The number of segments the curve is divided into*/
};

#endif //HEAD_FUNCTIONLINE
