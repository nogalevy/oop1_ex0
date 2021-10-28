#include "Triangle.h"

// -----================ constructors ================-----

Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{	
	if (!(m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& sameRow(m_v0, m_v1) && m_v1.isToTheRightOf(m_v0)
		&& doubleEqual(getLength(), distance(m_v1, m_v2))
		&& doubleEqual(getLength(), distance(m_v0, m_v2))))
		setDefault();
}

//------------------------------------

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	:m_v0(v0), m_v1(v1), m_v2(Vertex((m_v1.m_col - m_v0.m_col) / 2, m_v0.m_row + height))
{
	if (!(m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& sameRow(m_v0, m_v1) && m_v1.isToTheRightOf(m_v0)
		&& doubleEqual(distance(m_v0, m_v2), distance(m_v1, m_v0))))
			setDefault();
	
}

// -----================ main functions (public) ================-----

Vertex Triangle::getVertex(int index) const
{
	switch (index)
	{
	case 0:
		return m_v0;
	case 1:
		return m_v1;
	case 2:
		return m_v2;
	default:
		return m_v2;
	}
}

//------------------------------------

double Triangle::getLength() const
{
	return distance(m_v0, m_v2);
}

//------------------------------------

double Triangle::getHeight() const
{
	return (m_v2.m_row - m_v0.m_row);
}

//------------------------------------

void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v2, m_v0);
}

//------------------------------------

double Triangle::getArea() const
{
	return abs((getLength() * getHeight()) / 2);
}

//------------------------------------

double Triangle::getPerimeter() const
{
	return (3 * getLength());
}

//------------------------------------

Vertex Triangle::getCenter() const
{
	return Vertex((m_v0.m_col + m_v1.m_col + m_v2.m_col) / 3,
		(m_v0.m_row + m_v1.m_row + m_v2.m_row) / 3);
}

//------------------------------------

bool Triangle::scale(double factor)
{

	if (factor <= 0)
		return false;

	Vertex center = getCenter();
	Vertex new_v0, new_v1, new_v2;

	double xdiff = factor * (center.m_col - m_v0.m_col),
		   ydiff = factor * (center.m_row - m_v0.m_row);

	new_v0 = Vertex(center.m_col - xdiff, center.m_row - ydiff);
	new_v1 = Vertex(center.m_col + xdiff, center.m_row - ydiff);
	new_v2 = Vertex(center.m_col, center.m_row + ydiff);

	if (!new_v0.isValid() || !new_v1.isValid() || !new_v2.isValid())
		return false;

	m_v0 = new_v0;
	m_v1 = new_v1;
	m_v2 = new_v2;

	return true;
}

//------------------------------------

Rectangle Triangle::getBoundingRectangle() const
{
	if (getHeight() < 0)
		return Rectangle(Vertex(m_v0.m_col, m_v2.m_row), m_v1);

	return Rectangle(m_v0, Vertex(m_v1.m_col, m_v2.m_row));
}


// -----================ sub functions (private) ================-----

void Triangle::setDefault()
{
	m_v0 = Vertex(20, 20);
	m_v1 = Vertex(30, 20);
	m_v2 = Vertex(25, 20 + sqrt(7));
}

