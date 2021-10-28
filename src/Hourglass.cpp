#include "Hourglass.h"

// -----================ constructors ================-----

Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_lower(lower), m_upper(upper)
{
	if (!(doubleEqual(upper.getLength(), lower.getLength())
		&& (verticesEqual(upper.getVertex(2), lower.getVertex(2)))
		&& (upper.getVertex(0).isHigherThan(lower.getVertex(0)))))
		 setDefault();
}

//------------------------------------

Hourglass::Hourglass(const Triangle& lower)
	:m_lower(lower), m_upper(lower)
{
	Vertex vertices[3];
	vertices[0] = Vertex(lower.getVertex(0).m_col, (lower.getVertex(0)).m_row + 2 * lower.getHeight());
	vertices[1] = Vertex((lower.getVertex(1)).m_col, (lower.getVertex(1)).m_row + 2 * lower.getHeight());
	vertices[2] = lower.getVertex(2);

	if (vertices[0].isValid() && vertices[1].isValid() && sameRow(vertices[0], vertices[1]))
		m_upper = Triangle(vertices);

	else 
		setDefault();
}

// -----================ main functions (public) ================-----

double Hourglass::getLength() const
{
	return m_lower.getLength();
}

//------------------------------------

double Hourglass::getHeight() const
{
	return abs(2 * (m_lower.getHeight()));
}

//------------------------------------

double Hourglass::getArea() const
{
	return 2 * m_lower.getArea();
}

//------------------------------------

double Hourglass::getPerimeter() const
{
	return 2 * m_lower.getPerimeter();
}

//------------------------------------

Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}

//------------------------------------

void Hourglass::draw(Board& board) const
{
	m_upper.draw(board);
	m_lower.draw(board);
}

//------------------------------------

bool Hourglass::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex center = getCenter(),
		   upper_vertices[3],
		   lower_vertices[3];

	double xdiff = factor * (center.m_col - m_lower.getVertex(0).m_col),
		   ydiff = factor * (center.m_row - m_lower.getVertex(0).m_row);

	lower_vertices[0] = Vertex(center.m_col - xdiff, center.m_row - ydiff);
	lower_vertices[1] = Vertex(center.m_col + xdiff, center.m_row - ydiff);
	upper_vertices[0] = Vertex(center.m_col - xdiff, center.m_row + ydiff);
	upper_vertices[1] = Vertex(center.m_col + xdiff, center.m_row + ydiff);
	lower_vertices[2] = upper_vertices[2] = center;

	if (!lower_vertices[0].isValid() || !lower_vertices[1].isValid() || !upper_vertices[0].isValid() || !upper_vertices[1].isValid())
		return false;

	
	m_upper = Triangle(upper_vertices);
	m_lower = Triangle(lower_vertices);

	return true;
}

//------------------------------------

Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(1));
}


// -----================ sub functions (private) ================-----

void Hourglass::setDefault()
{
	Vertex verticesUpper[3], verticesLower[3];
	verticesUpper[0] = Vertex(20, 20 + 2 * sqrt(75));
	verticesUpper[1] = Vertex(30, 20 + 2 * sqrt(75));
	verticesUpper[2] = Vertex(25, 20 + sqrt(75));

	verticesLower[0] = Vertex(20, 20);
	verticesLower[1] = Vertex(30, 20);
	verticesLower[2] = Vertex(25, 20 + sqrt(75));

	m_upper = Triangle(verticesUpper);
	m_lower = Triangle(verticesLower);
}

