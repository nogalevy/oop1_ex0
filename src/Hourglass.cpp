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
		Vertex v0, v1;
		v0.m_row = v1.m_row = (lower.getVertex(0)).m_row + m_height;
		v0.m_col = (lower.getVertex(0)).m_col;
		v1.m_col = (lower.getVertex(1)).m_col;
		Triangle upper(v0, v1, (-1 * lower.getHeight()));
		m_upper = upper;
	}

	else
		//set Default
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
	/*
	m_lower = Triangle()
	
	m_v0.m_col = m_v0.m_row = m_v1.m_row = 20;
	m_v1.m_col = 30;
	m_v2.m_col = 25;
	m_v2.m_row = 20 + sqrt(75);
	m_len = distance(m_v0, m_v1);
	m_height = calcHeight();
	*/

	Triangle upper(, lower
			 lower (;

}