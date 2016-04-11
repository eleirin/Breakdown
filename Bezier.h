/*! \file Bezier.h
 */
#ifndef HEAD_BEZIER
#define HEAD_BEZIER
#include <array>
#include "MathVector.h"
#include "FunctionLine.h"

/*! \brief A generic bezier line with N points
 *
 * This class implements a dynamic bezier line. Any control points can be
 * accessed and modified with the [] operator.
 * It is to be noted that as of yet, the Bezier curve is recomputed every time.
 * This is because the class design wants to be very simple of use and not have
 * any afterDraw or update function, and it would be the only way to know wether * a control point has been modified or not. This should however not be a
 * problem: Keep the BezierLine if you are about to change it, otherwise simply
 * convert it to a VertexArray via its conversion operato.
 * Moreover, the number of control points is fixed because adding or deleting one would imply recalculating Pascal's binom. That might change in the future.
 *
 * This class simply computes a function that will be drawn by the FunctionLine
 * (see Wikipedia for the general function)
 *
 * \tparam N the number of control points on the Bezier Curve
 */
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
    static MathVector barycenter(const std::array<float, N> &ponderation, const std::array<MathVector, N> &points);

    const std::function<MathVector(float)> m_Fun; /*!< The function of the bezier curve*/
    static std::array<float, N> m_Binom; /*!< The binoms of rank N-1, that we compute before hand. It is declared float to avoid impromptu casts*/
    std::array<MathVector, N> m_ControlPoints; /*!< The list of the control points*/
};

#include "Bezier.tpp"
#endif //HEAD_BEZIER
