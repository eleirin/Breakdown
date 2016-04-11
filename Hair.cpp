
class Strand
{
public:
    Strand();
    virtual ~Strand();

private:
    struct Node : MathVector
    {
    };
    std::array<Node, N> m_Vertices;

}
