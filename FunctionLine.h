#ifndef HEAD_FUNCTIONLINE
#define HEAD_FUNCTIONLINE
#include <SFML/Graphics.hpp>
#include <functional>
#include "MathVector.h"

class FunctionLine: public sf::Drawable
{
public:
    FunctionLine(const std::function<MathVector(float)> &f, int steps = 50, sf::Color begin = sf::Color::Yellow, sf::Color end = sf::Color::Blue);
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
