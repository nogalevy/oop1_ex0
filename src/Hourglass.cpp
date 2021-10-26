#include "Hourglass.h"

Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_lower(lower), m_upper(upper)
{
	if ((upper.getLength() == lower.getLength())
		&& (verticesEqual(upper.getVertex(2), lower.getVertex(2)))
		&& (upper.getVertex(0).isHigherThan(lower.getVertex(0))))
	{
		m_upper = upper;
		m_lower = lower;
		m_len = upper.getLength();
		m_height = upper.getHeight() + lower.getHeight();
	}

	else
		setDefault();
}

Hourglass::Hourglass(const Triangle& lower)
	:m_lower(lower), m_upper(lower)
{
	if (0 <= (lower.getVertex(0)).m_col + lower.getHeight() <= MAX_COL)
	{
		m_lower = lower;
		m_len = lower.getLength();
		m_height = 2 * lower.getHeight();

		//creating upper triangle
		Vertex v0((lower.getVertex(0)).m_col, (lower.getVertex(0)).m_row + m_height),
			v1((lower.getVertex(1)).m_col, (lower.getVertex(0)).m_row + m_height);

		m_upper = Triangle(v0, v1, (-1 * lower.getHeight()));;
	}

	else
		setDefault();
}

double Hourglass::getLength() const
{
	return m_len;
}

double Hourglass::getHeight() const
{
	return m_height;
}

void Hourglass::setDefault()
{
	Vertex verticesUpper[3], verticesLower[3];
	verticesUpper[0] = Vertex(20, 20 + 2 * sqrt(75));
	verticesUpper[1] = Vertex(30, 20 + 2 * sqrt(75));
	verticesUpper[2] = Vertex(25, 20 + sqrt(75));
	verticesLower[0] = Vertex(20, 20);
	verticesLower[1] = Vertex(30, 20);
	verticesLower[2] = verticesUpper[2];

	m_upper = Triangle(verticesUpper);
	m_lower = Triangle(verticesLower);
}


double Hourglass::getArea()
{
	return 2 * m_lower.getArea();
}

double Hourglass::getPerimeter()
{
	return 6 * m_len;
}

Vertex Hourglass::getCenter()
{
	return m_lower.getVertex(2);
}


void Hourglass::draw(Board& board)
{
	m_upper.draw(board);
	m_lower.draw(board);
}


bool Hourglass::scale(double factor)
{
	return m_upper.scale(factor) && m_lower.scale(factor);
}