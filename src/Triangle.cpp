#include "Triangle.h"


Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{
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
	:m_v0(v0), m_v1(v1), m_height(height)
{
	if (v0.isValid() && v1.isValid()
		&& sameRow(v0, v1) && v1.isToTheRightOf(v0))
	{
		m_len = distance(v0, v1);
		m_v2.m_col = v0.m_col + (m_len / 2); 
		m_v2.m_row = v0.m_row + height;

		if (m_v2.isValid())
		{
			m_v0 = v0;
			m_v1 = v1;

			return;
		}
	}

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
		return m_v2;
	}
}

double Triangle::getLength() const
{
	return m_len;
}

double Triangle::getHeight() const
{
	return m_height;
}

double Triangle::calcHeight()
{
	Vertex midpoint(m_v2.m_col, m_v0.m_row);

	return distance(m_v2, midpoint);
}

void Triangle::setDefault()
{
	m_v0 = Vertex(20, 20);
	m_v1 = Vertex(30, 20);
	m_v2 = Vertex(25, 20 + std::sqrt(7));

	m_len = distance(m_v0, m_v1);
	m_height = calcHeight();
}


void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v2, m_v0);
}

double Triangle::getArea() const
{
	return std::abs((m_len * m_height) / 2);
}

double Triangle::getPerimeter() const 
{
	return (3 * m_len);
}

Vertex Triangle::getCenter() const
{
	return Vertex((m_v0.m_col + m_v1.m_col + m_v2.m_col) / 3,
		(m_v0.m_row + m_v1.m_row + m_v2.m_row) / 3);
}


bool Triangle::scale(double factor)
{
	Vertex center = getCenter();
	Vertex new_v0, new_v1, new_v2;

	if (m_height > 0)
	{
		new_v0 = Vertex(center.m_col - (center.m_col - m_v0.m_col) * factor, center.m_row - (center.m_row - m_v0.m_row) * factor);
		new_v1 = Vertex(center.m_col + (m_v1.m_col - center.m_col) * factor, new_v0.m_row);
		new_v2 = Vertex(center.m_col, center.m_row + (m_v2.m_row - center.m_row) * factor);
	}
	else
	{
		new_v0 = Vertex(center.m_col - (center.m_col - m_v0.m_col) * factor, center.m_row + (m_v0.m_row - center.m_row) * factor);
		new_v1 = Vertex(center.m_col + (m_v1.m_col - center.m_col) * factor, new_v0.m_row);
		new_v2 = Vertex(center.m_col, center.m_row - (center.m_row - m_v2.m_row) * factor);
	}


	if (factor < 0 || !new_v0.isValid() || !new_v1.isValid() || !new_v2.isValid())
		return false;

	m_v0 = new_v0;
	m_v1 = new_v1;
	m_v2 = new_v2;

	return true;
}

Rectangle Triangle::getBoundingRectangle() const
{
	if (m_height < 0)
		return Rectangle(Vertex(m_v0.m_col, m_v2.m_row), m_len, std::abs(m_height));

	return Rectangle(m_v0, m_len, m_height);
}