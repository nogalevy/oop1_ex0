
#include "Rectangle.h"

#include "Vertex.h"

#include <iostream>


//------------- constructor ------------------
/*
default rectangle
*/
Rectangle::Rectangle()
    : m_bottomLeft(Vertex(20.0, 10.0)),
    m_topRight(Vertex(30.0, 20.0))
{
  saveVertices(m_bottomLeft, m_topRight);
}

Rectangle::Rectangle (const Vertex& bottomLeft, const Vertex& topRight)
{
  if(topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft))
  {
    if(bottomLeft.isValid() && topRight.isValid())
    {
        saveVertices(bottomLeft, topRight);
        std::cout << " \n -- is valid = here !! ---\n" << m_bottomLeft.m_col << "\n";;
        return;
    }
  }
  Rectangle();
}

Rectangle::Rectangle (const Vertex vertices[2])
{
   std::cout << " \n -- FROM ARRAY !! ---\n" << vertices[0].m_col << "\n";
  Rectangle(vertices[0], vertices[1]);
  return;
}

Rectangle::Rectangle (double x0, double y0, double x1, double y1)
{
  Rectangle(Vertex(x0, y0), Vertex(x1, y1));
}

Rectangle::Rectangle (const Vertex& start, double width, double height)
{
  if(width < 0 || height < 0)
    Rectangle();

  auto t_r = Vertex(start.m_col + width, start.m_row + height);
  Rectangle(start, t_r);
}

//------------------- main functions -------------------

 //return BL vertex
Vertex Rectangle::getBottomLeft()const
{
    std::cout << m_bottomLeft.m_col;
    return m_bottomLeft;
}
//return TR vertex
Vertex Rectangle::getTopRight()const
{
    return m_topRight;
}
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
    std::cout << "\n!!!!! === in draw === !!!!\n";
    std::cout << m_bottomLeft.m_col << "\n";
    std::cout << m_topLeft.m_col << "\n";

    board.drawLine(m_bottomLeft, m_topLeft);
    board.drawLine(m_topLeft, m_topRight);
    board.drawLine(m_topRight, m_bottomRight);
    board.drawLine(m_bottomRight, m_bottomLeft);
}

Rectangle Rectangle::getBoundingRectangle() const
{
    auto r = Rectangle(Vertex(0, 17), Vertex(24, 31));
    return r;
}

double Rectangle::getArea()const
{
    return 1;
}

double Rectangle::getPerimeter()const
{
    return 1;
}
Vertex Rectangle::getCenter()const
{
    return Vertex(2, 2);
}

bool Rectangle::scale(double factor)
{
    return true;
}

//------------------------ sub function -------------------------------
void Rectangle::saveVertices(const Vertex& bottomLeft, const Vertex& topRight)
{
  m_bottomLeft = bottomLeft;
  m_bottomRight = Vertex(topRight.m_col, bottomLeft.m_row);
  m_topRight = topRight;
  m_topLeft = Vertex(bottomLeft.m_col, topRight.m_row);

  std::cout << "\n\n ----- MTL = " << m_topLeft.m_col << "\n";
}
