#include <cmath>
#include <iostream>

template <int N>
std::array<float, N> BezierLine<N>::computeBinom(void)
{
    std::array<float, N> result;
    int currentBinom = 1;
    result[0] = currentBinom;

    for(int i = 1; i < N; i++)
    {
        currentBinom = (N - i) * currentBinom / i;
        result[i] = currentBinom;
    }
    return result;
}

template<int N> 
std::array<float, N> BezierLine<N>::m_Binom = BezierLine<N>::computeBinom();

template <int N>
MathVector BezierLine<N>::barycenter(const std::array<float, N> &ponderation,
const std::array<MathVector, N> &points)
{
    MathVector result;
    float divider = 0;

    for(int i = 0; i < N; i++)
    {
        result += ponderation[i] * points[i];
        divider += ponderation[i];
    }

    return result / divider;
}

template <int N>
BezierLine<N>::BezierLine(int steps):
    FunctionLine(m_Fun, steps)
{
   m_Fun = [this](float t)
   {
        std::array<float, N> ponderation = m_Binom;

        for(int i = 0; i < N; i++)
        {
            ponderation[i] *= float(pow((1 - t), i) * pow(t, N - 1 - i));
        }

        return barycenter(ponderation, m_ControlPoints);
   };
}

template <int N>
BezierLine<N>::BezierLine(const std::array<MathVector, N> &a, int steps):
    BezierLine(steps)
{
    changeAllControlPoints(a);
}

template <int N>
BezierLine<N>::~BezierLine()
{
}

 template <int N>
const MathVector &BezierLine<N>::operator[](int i) const
{
    return m_ControlPoints[i];
}

 template <int N>
MathVector &BezierLine<N>::operator[](int i)
{
    return m_ControlPoints[i];
}

template <int N>
void BezierLine<N>::changeAllControlPoints(const std::array<MathVector, N> &a)
{
    for(int i = 0; i < N; i++)
    {
        m_ControlPoints[i] = a[i];
    }
}
