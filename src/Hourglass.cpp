#include "Hourglass.h"


Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
{
	//receives two "correctly built" triangles
	//(1) check that side lengths are equal
	//(2) checks that there is one shared vertex and that the upper triangle faces upward and vice versa
	//if (1) or (2) fail, create default hourglass

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
{
	//check if able to build upper triangle or if it will be outside of board
	//if not builds default?
	if (0 <= (lower.getVertex(0)).m_col + lower.getHeight() <= MAX_COL)
	{
		m_lower = lower;
		m_len = lower.getLength();
		m_height = 2 * lower.getHeight();

		//creating upper triangle
		Vertex v0((lower.getVertex(0)).m_col, (lower.getVertex(0)).m_row + m_height),
			v1((lower.getVertex(1)).m_col, (lower.getVertex(0)).m_row + m_height);

		Triangle upper(v0, v1, (-1 * lower.getHeight()));
		m_upper = upper;
	}

	else
		setDefault();
}

double Hourglass::getLength() const
{
	//returns length of sides of hourglass
	return m_len;
}

double Hourglass::getHeight() const
{
	//returns height of hourglass (sum of heights of triangles)
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
	verticesLower[2] = Vertex(25, 20 + sqrt(75));
	Triangle upper(verticesUpper),
			 lower(verticesLower);

	m_upper = upper;
	m_lower = lower;
}