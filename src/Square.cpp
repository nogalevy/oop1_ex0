#include "Square.h"



// -----================ constructors ================-----
//----
Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
    : m_square(Vertex(20, 10), Vertex(30, 20)) //set default
{
    Vertex t_l(bottomLeft.m_col, topRight.m_row);
    //check if width and heigh are equale
    if (doubleEqual(distance(t_l, topRight), distance(t_l, bottomLeft)))
    {
      m_square = Rectangle(bottomLeft, topRight);
    }
}

//----
Square::Square(const Vertex& start, double length)
	:Square(start, Vertex(start.m_col + length, start.m_row + length))
{ }



// -----================ main functions (public) ================-----
//----
Vertex Square::getBottomLeft()const
{
    return m_square.getBottomLeft();
}

//----
Vertex Square::getTopRight()const
{
    return m_square.getTopRight();
}

//----
double Square::getLength()const
{
    return m_square.getHeight(); //width and height are equale in squre
}

//----
void Square::draw(Board& board)const
{
    m_square.draw(board);
}

//----
Rectangle Square::getBoundingRectangle() const
{
    return m_square;
}

//----
double Square::getArea()const
{
    return m_square.getArea();
}

//----
double Square::getPerimeter()const
{
    return m_square.getPerimeter();
}

//----
Vertex Square::getCenter()const
{
    return m_square.getCenter();
}

//----
bool Square::scale(double factor)
{
    return m_square.scale(factor);
}
