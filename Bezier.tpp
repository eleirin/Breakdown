/* \file Bezier.tpp
 */

#include <cmath>
#include <iostream>

/*! \brief Compute all of the pascal binomials of rank N-1
 *
 * This function shall be useful since the function of the bezier curve uses
 * them a lot
 *
 * \todo Move computeBinom where it belongs (a math library/file)
 * 
 * \tparam N The rank on which we will compute the binom
 * \return An array of the binomials of rank N-1
 */
template <int N>
std::array<float, N> BezierLine<N>::computeBinom(void)
{
    /* We will use the fact that C(n, k+1) = C(n, k) * (n + 1 - i) / i*/
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

/*! \brief Compute the barycenter of N points with their respective coefficients
 *
 * This function will be very useful to a lot of parametric function
 * manipulation
 * \todo Move barycenter where it belongs (MathVector)
 *
 * \tparam N The number of points to take the barycenter of
 * \return The barycenter of all points pondered by their respective
 * coefficients
 */
 template <int N>
MathVector BezierLine<N>::barycenter(
    const std::array<float, N> &ponderation,
    /*!< The array of coefficients. ponderation[i] is the coefficient of the
     *    ith point.
     * \warning{The sum of all the elements must be non-null, or it will cause
     * a division by zero elsewise}
     * \todo Throw exception when the sum of ponderation is null*/

    const std::array<MathVector, N> &points
    /*!< The array of the points to ponder*/)
{
    /* We simply multiply every points with their coefficient and then divide by
     * the sum of ponderation */
    MathVector result;
    float divider = 0;

    for(int i = 0; i < N; i++)
    {
        result += ponderation[i] * points[i];
        divider += ponderation[i];
    }

    return result / divider;
}

/*! \brief Constructor of an empty BezierCurve (All points are on the (0, 0)
 * point
 */
template <int N>
BezierLine<N>::BezierLine(
    int steps
    /*!< The number of points we will use to smooth the curve*/)
: 
    FunctionLine(m_Fun, steps)
{
   /* We define the function m_Fun
    * It is to be noted m_Fun will never be modified, thanks to the magic of
    * capture, only the points will be
    */
   m_Fun = [this](float t)
   {
        // See wikipedia for the formula
        std::array<float, N> ponderation = m_Binom;

        for(int i = 0; i < N; i++)
        {
            ponderation[i] *= float(pow(t, i) * pow((1 - t), N - 1 - i));
        }

        return barycenter(ponderation, m_ControlPoints);
   };
}

/*! \brief Constructor of a BezierCurve with predefined control points
 */
template <int N>
BezierLine<N>::BezierLine(
    const std::array<MathVector, N> &a,
    /*!< The control points the bezier line should use */

    int steps
    /*!< The number of points we will use to smooth the curve*/)
:
    BezierLine(steps)
{
    changeAllControlPoints(a);
}

/*! \brief Destructor of BezierLine
 */
template <int N>
BezierLine<N>::~BezierLine()
{
}

/*! \brief Const access to the i-th control point of the curve
 *
 * \return A const reference to the i-th control point, it may not be modified
 */
 template <int N>
const MathVector &BezierLine<N>::operator[](
    int i
    /*!< The number of the control point to access*/) const
{
    return m_ControlPoints[i];
}

/*! \brief Modifying access to the i-th control point of the curve
 *
 * \return A reference to the i-th control point that may be modified
 */
 template <int N>
MathVector &BezierLine<N>::operator[](
    int i
    /*!< The number of the control point to modify*/)
{
    return m_ControlPoints[i];
}

/*! \brief Modify all of the control points to defined value
 */
template <int N>
void BezierLine<N>::changeAllControlPoints(
    const std::array<MathVector, N> &a
    /*!< The array to copy the control points from*/)
{
    for(int i = 0; i < N; i++)
    {
        m_ControlPoints[i] = a[i];
    }
}
