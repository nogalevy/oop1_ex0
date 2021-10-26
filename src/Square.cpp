
#include "Square.h"


Square::Square(const Vertex& bottomLeft, const Vertex& topRight)
    : m_square(Vertex(20, 10), Vertex(30, 20))
{
    Vertex t_l(bottomLeft.m_col, topRight.m_row);
    if (doubleEqual(distance(t_l, topRight), distance(t_l, bottomLeft)))
    {
        Rectangle new_square = Rectangle(bottomLeft, topRight);
       
        m_square = new_square;
        // m_square =Rectangle(bottomLeft, topRight);
    }
       
}


Square::Square(const Vertex& start, double length)
	:Square(start, Vertex(start.m_col + length, start.m_row + length))
{ }


//------------------- main functions -------------------

 //return BL vertex
Vertex Square::getBottomLeft()const
{
    return m_square.getBottomLeft();
}

//return TR vertex
Vertex Square::getTopRight()const
{
    return m_square.getTopRight();
}

//use distance in utilitties
//return width (Xr - Xl)
double Square::getLength()const
{
    //width and height are equale in squre so I choose to use height
    return m_square.getHeight();
}



//draw the Rectangle
void Square::draw(Board& board)const
{
    m_square.draw(board);
    //BL -> TL    //TL -> TR    //TR -> BR    //BR -> BL
    /*
    auto b_l = m_square.getBottomLeft(),
        t_r = m_square.getTopRight(),
        b_r = Vertex(b_l.m_col ,t_r.m_row),
        t_l = Vertex(t_r.m_col, b_l.m_row);

    board.drawLine(b_l, t_l);
    board.drawLine(t_l, t_r);
    board.drawLine(t_r, b_r);
    board.drawLine(b_r, b_l);
    */
}


Rectangle Square::getBoundingRectangle() const
{
    return m_square;
}

double Square::getArea()const
{
    return m_square.getArea();
}

double Square::getPerimeter()const
{
    return m_square.getPerimeter();
}

Vertex Square::getCenter()const
{
    return m_square.getCenter();
}

bool Square::scale(double factor)
{
    return true;
}
