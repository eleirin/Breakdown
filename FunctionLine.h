/* \file FunctionLine.h
 * Define the FunctionLine class
 */

#ifndef HEAD_FUNCTIONLINE
#define HEAD_FUNCTIONLINE
#include <SFML/Graphics.hpp>
#include <functional>
#include "MathVector.h"

/* \brief A class that will draw a parametric function from [0, 1] to R2
 *
 */
class FunctionLine: public sf::Drawable
{
public:
    FunctionLine(const std::function<MathVector(float)> &f, int steps = 50, sf::Color begin = sf::Color::Magenta, sf::Color end = sf::Color::Cyan);
    virtual ~FunctionLine();

    operator sf::VertexArray(void) const;
    virtual void draw(sf::RenderTarget &rt, sf::RenderStates s) const override;

private:
    const std::function<MathVector(float)> &m_Fun;
    const int m_Steps;
    sf::Color m_Begin;
    sf::Color m_End;
};

#endif //HEAD_FUNCTIONLINE
