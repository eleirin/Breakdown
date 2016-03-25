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
        const float fint = 1.f - t;
        result[i].position = m_Fun(t);
        result[i].color = sf::Color(t * m_Begin.r + fint * m_End.r, t * m_Begin.g + fint * m_End.g, t * m_Begin.b + fint * m_End.b);
    }

    return result;
}

void FunctionLine::draw(sf::RenderTarget &rt, sf::RenderStates s) const
{
    sf::VertexArray a = operator sf::VertexArray();
    rt.draw(a, s); 
}
