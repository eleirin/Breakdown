#ifndef HEAD_BEZIER
#define HEAD_BEZIER
#include <array>
#include "MathVector.h"
#include "FunctionLine.h"

template <int N>
class BezierLine: public FunctionLine
{
public:
    BezierLine(int steps = 50);
    BezierLine(const std::array<MathVector, N> &a, int steps = 50);
    ~BezierLine();

    const MathVector &operator[](int i) const;
    MathVector &operator[](int i);
    void changeAllControlPoints(const std::array<MathVector, N> &a);

private:
    static std::array<float, N> computeBinom(void);
    static std::array<float, N> m_Binom;
    static MathVector barycenter(const std::array<float, N> &ponderation, const std::array<MathVector, N> &points);

    std::function<MathVector(float)> m_Fun;
    std::array<MathVector, N> m_ControlPoints;
};

#include "Bezier.tpp"
#endif //HEAD_BEZIER
