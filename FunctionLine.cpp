/* \file FunctionLine.cpp
 */

#include "FunctionLine.h"

/*! \brief Constructor of FunctionLine
 */
FunctionLine::FunctionLine(
    const std::function<MathVector(float)> &f, 
    /*!< The function that will be called every time we draw the FunctionLine*/

    int steps,
    /*!< The number of segments we use to draw the curve.*/

    sf::Color begin,
    /*!< The color at the beginning of the curve*/

    sf::Color end
    /*!< The color at the end of the curve*/) 
: 
    m_Begin(begin),
    m_End(end),
    m_Fun(f),
    m_Steps(steps)
{
}

/*! \brief Destructor of FunctionLine
 */
FunctionLine::~FunctionLine()
{
}

/*! \brief Converts the FunctionLine into a VertexArray
 *
 * This function allows us to do
 * \code{cpp}
 *  VertexArray a = FunctionLine(f);
 * \endcode{}
 * Which is pretty convenient, since that prevents further recalculation of the
 * curve
 */
FunctionLine::operator sf::VertexArray(void) const
{
    sf::VertexArray result(sf::LinesStrip, m_Steps + 1);

    for(int i = 0; i <= m_Steps; i++)
    {
        /* For every point, we simply compute its position with a call to the
         * function*/
        const float t = float(i) / m_Steps;
        result[i].position = m_Fun(t);

        //RGB Interpolation from m_Begin to m_End
        //\todo{Turn it into a HSV interpolation}
        const float invt = 1.f - t;
        const int t_color= t * 255;
        const int invt_color= invt * 255;
        const sf::Color begin_coef = sf::Color(invt_color, invt_color, invt_color);
        const sf::Color end_coef = sf::Color(t_color, t_color, t_color);
        result[i].color = begin_coef * m_Begin + end_coef * m_End;
    }

    return result;
}

/*! \brief Draw the function line
 *
 * This will compute all the values of the function and draw it as a curve
 */
void FunctionLine::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    sf::VertexArray a = operator sf::VertexArray();
    rt.draw(a, s); 
}
