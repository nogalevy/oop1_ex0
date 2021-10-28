#include "Rectangle.h"


// -----================ constructors ================-----
//----
Rectangle::Rectangle (const Vertex& bottomLeft, const Vertex& topRight)
    : m_bottomLeft(bottomLeft), m_topRight(topRight) 
{
  if((topRight.isHigherThan(bottomLeft) && topRight.isToTheRightOf(bottomLeft) || verticesEqual(bottomLeft, topRight))
      && (bottomLeft.isValid() && topRight.isValid()))
    {
        saveVertices(bottomLeft, topRight);
        return;
    }
  saveDefault();
}

//----
Rectangle::Rectangle (const Vertex vertices[2])
    : Rectangle(vertices[0], vertices[1])
{ }

//----
Rectangle::Rectangle (double x0, double y0, double x1, double y1)
    : Rectangle(Vertex(x0, y0), Vertex(x1, y1))
{ }

//----
Rectangle::Rectangle (const Vertex& start, double width, double height)
{
    if (width <= 0 || height <= 0)
        saveDefault();

    saveVertices(start, Vertex(start.m_col + width, start.m_row + height));
}

// -----================ main functions (public) ================-----
//----
Vertex Rectangle::getBottomLeft()const
{
    return m_bottomLeft;
}

//----
Vertex Rectangle::getTopRight()const
{
    return m_topRight;
}

//----
double Rectangle::getWidth()const
{
    return m_width;
}

//----
double Rectangle::getHeight()const
{
    return m_height;
}

//----
void Rectangle::draw(Board& board)const
{
    //draw:
    //b_l -> t_l   t_l -> t_r    t_r -> b_r   b_r -> b_l
    Vertex t_l = Vertex(m_bottomLeft.m_col, m_topRight.m_row),
            b_r = Vertex(m_topRight.m_col, m_bottomLeft.m_row);;

    board.drawLine(m_bottomLeft, t_l);
    board.drawLine(t_l, m_topRight);
    board.drawLine(m_topRight, b_r);
    board.drawLine(b_r, m_bottomLeft);
}

//----
Rectangle Rectangle::getBoundingRectangle() const
{
    return *this;
}

//----
double Rectangle::getArea()const
{
    return (m_height * m_width);
}

//----
double Rectangle::getPerimeter()const
{
    return (2*m_height + 2*m_width);
}

//----
Vertex Rectangle::getCenter()const
{
    double x = m_bottomLeft.m_col + (m_width / 2);
    double y = m_bottomLeft.m_row + (m_height / 2);

    return Vertex(x, y);
}

//----
bool Rectangle::scale(double factor)
{
    Vertex center = getCenter();
    Vertex new_b_l, new_t_r;

    if (factor < 0) return false;

    new_b_l = Vertex(center.m_col - (center.m_col - m_bottomLeft.m_col) * factor, 
                    center.m_row - (center.m_row - m_bottomLeft.m_row) * factor);
    new_t_r = Vertex(center.m_col + (m_topRight.m_col - center.m_col) * factor,
                    center.m_row + (m_topRight.m_row - center.m_row) * factor);
 
    if (!new_b_l.isValid() || !new_t_r.isValid()) return false;

    m_bottomLeft = new_b_l;
    m_topRight = new_t_r;

    return true;
}


// -----================ sub functions (private) ================-----
//----
void Rectangle::saveDefault()
{
    saveVertices(Vertex(20, 10), Vertex(30, 20));
}

//----
void Rectangle::saveVertices(const Vertex& bottomLeft, const Vertex& topRight)
{
    auto b_r = Vertex(m_topRight.m_col, m_bottomLeft.m_row);
    m_bottomLeft = bottomLeft;
    m_topRight = topRight;

    m_height = distance(b_r, m_topRight); // y
    m_width = distance(b_r, m_topRight);  // x
}

