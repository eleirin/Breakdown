#include <functional>
#include "FunctionLine.h"

FunctionLine::FunctionLine(const std::function<MathVector(float)> &f, int steps, sf::Color begin, sf::Color end): 
    m_Fun(f),
    m_Steps(steps),
    m_Begin(begin),
    m_End(end)
{
}

FunctionLine::~FunctionLine()
{
}

FunctionLine::operator sf::VertexArray(void) const
{
    sf::VertexArray result(sf::LinesStrip, m_Steps + 1);

    for(int i = 0; i <= m_Steps; i++)
    {
        const float t = float(i) / m_Steps;
        const float invt = 1.f - t;
        result[i].position = m_Fun(t);

        const int t_color= t * 255;
        const int invt_color= invt * 255;
        const sf::Color begin_coef = sf::Color(invt_color, invt_color, invt_color);
        const sf::Color end_coef = sf::Color(t_color, t_color, t_color);
        result[i].color = begin_coef * m_Begin + end_coef * m_End;
    }

    return result;
}

void FunctionLine::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    sf::VertexArray a = operator sf::VertexArray();
    rt.draw(a, s); 
}
