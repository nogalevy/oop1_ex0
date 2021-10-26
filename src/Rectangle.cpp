
#include "Rectangle.h"

#include <iostream>


//------------- constructor ------------------

Rectangle::Rectangle (const Vertex& bottomLeft, const Vertex& topRight)
    : m_bottomLeft(bottomLeft), m_topRight(topRight) 
{
  if(topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft)
      && (bottomLeft.isValid() && topRight.isValid()))
    {
        saveVertices(bottomLeft, topRight);
        return;
    }
  saveDefault();
}

Rectangle::Rectangle (const Vertex vertices[2])
  : Rectangle(vertices[0], vertices[1])
{ }

Rectangle::Rectangle (double x0, double y0, double x1, double y1)
    : Rectangle(Vertex(x0, y0), Vertex(x1, y1))
{ }


// !!! ask about the Vertex-auto
Rectangle::Rectangle (const Vertex& start, double width, double height)
{
    //auto t_r = Vertex(start.m_col + width, start.m_row + height);
    if (width < 0 || height < 0)
        saveDefault();

   saveVertices(start, Vertex(start.m_col + width, start.m_row + height));
}

//------------------- main functions -------------------

 //return BL vertex
Vertex Rectangle::getBottomLeft()const
{
    return m_bottomLeft;
}

//return TR vertex
Vertex Rectangle::getTopRight()const
{
    return m_topRight;
}

//use distance in utilitties
//return width (Xr - Xl)
double Rectangle::getWidth()const
{
    return m_topRight.m_col - m_topLeft.m_col;
}
//return height (Yt - Yb)
double Rectangle::getHeight()const
{
    return  m_topRight.m_row - m_topRight.m_row;
}


//draw the Rectangle
void Rectangle::draw(Board& board)const
{
    //BL -> TL    //TL -> TR    //TR -> BR    //BR -> BL
    board.drawLine(m_bottomLeft, m_topLeft);
    board.drawLine(m_topLeft, m_topRight);
    board.drawLine(m_topRight, m_bottomRight);
    board.drawLine(m_bottomRight, m_bottomLeft);
}


Rectangle Rectangle::getBoundingRectangle() const
{
    return *this;
}

double Rectangle::getArea()const
{
    return m_height* m_width;
}

double Rectangle::getPerimeter()const
{
    return 2*m_height + 2*m_width;
}

Vertex Rectangle::getCenter()const
{
    double x = m_bottomLeft.m_col + (m_width / 2);
    double y = m_bottomLeft.m_row + (m_height / 2);

    return Vertex(x, y);
}

bool Rectangle::scale(double factor)
{
    return true;
}

//------------------------ sub function -------------------------------
void Rectangle::saveDefault()
{
    saveVertices(Vertex(20, 10), Vertex(30, 20));
    m_height = m_width = DEFAULT_LEN;
}

void Rectangle::saveVertices(const Vertex& bottomLeft, const Vertex& topRight)
{
  m_bottomLeft = bottomLeft;
  m_bottomRight = Vertex(topRight.m_col, bottomLeft.m_row);
  m_topRight = topRight;
  m_topLeft = Vertex(bottomLeft.m_col, topRight.m_row);

  m_height = distance(m_bottomLeft , m_topLeft);  // y
  m_width = distance(m_bottomLeft, m_bottomRight);  // x
}

