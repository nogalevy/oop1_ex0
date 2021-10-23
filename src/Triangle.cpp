#include "Triangle.h"

Triangle::Triangle(const Vertex vertices[3])
{
	//(1) check that values of vertices are valid (macros)
	//(2) check that first 2 vertices create a line parallel to x axis
	//(3) check that it is an equilateral triangle
	//if 1 2 or 3 are false, create default


	if (vertices[0].isValid() && vertices[1].isValid() && vertices[2].isValid()
		&& sameRow(vertices[0], vertices[1]) && vertices[1].isToTheRightOf(vertices[0])
		&& doubleEqual(m_len = distance(vertices[0], vertices[1]), distance(vertices[1], vertices[2]))
		&& doubleEqual(distance(vertices[1], vertices[2]), distance(vertices[2], vertices[0])))
	{
		m_v0 = vertices[0];
		m_v1 = vertices[1];
		m_v2 = vertices[2];

		m_height = calcHeight();
	}

	else
		setDefault();
}

Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
{
	//(1) check that values of vertices and height are valid (macros)
	//^height is length, send calculated vertex?
	//(2) check that first 2 vertices create a line parallel to x axis
	//(3) check that it is an equilateral triangle 
	//if 1 2 or 3 are false, create default
	//HEIGHT CAN BE NEGATIVE

	if (v0.isValid() && v1.isValid()
		&& sameRow(v0, v1) && v1.isToTheRightOf(v0))
	{
		m_len = distance(v0, v1);
		m_v2.m_col = v0.m_col + m_len / 2;
		m_v2.m_row = v0.m_row + height;

		if (m_v2.isValid() && doubleEqual(m_len, distance(v1, m_v2))
			&& doubleEqual(m_len, distance(m_v2, v0)))
		{
			m_v0 = v0;
			m_v1 = v1;
		}
	}

	else
		setDefault();
}

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
		//cout << "Incorrect index" << endl; //needed?
	}
}

double Triangle::getLength() const
{
	//returns length of side in triangle
	return m_len;
}

double Triangle::getHeight() const
{
	//returns length of height in triangle
	//line perpendicular to base of triangle
	return m_height;
}

double Triangle::calcHeight()
{
	Vertex midpoint;

	midpoint.m_col = m_v2.m_col;
	midpoint.m_row = m_v0.m_row;

	return distance(m_v2, midpoint);

}

void Triangle::setDefault()
{
	m_v0.m_col = m_v0.m_row = m_v1.m_row = 20;
	m_v1.m_col = 30;
	m_v2.m_col = 25;
	m_v2.m_row = 20 + sqrt(75);
	m_len = distance(m_v0, m_v1);
	m_height = calcHeight();
}