#include "Hourglass.h"

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

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
	Vertex v0((lower.getVertex(0)).m_col, (lower.getVertex(0)).m_row + 2*lower.getHeight()),
			v1((lower.getVertex(1)).m_col, (lower.getVertex(0)).m_row + 2*lower.getHeight());

	if (v0.isValid() && v1.isValid())
	{
		m_lower = lower;
		m_len = lower.getLength();
		m_height = 2* lower.getHeight();
		m_upper = Triangle(v0, v1, (-1 * lower.getHeight()));
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
	verticesUpper[0] = Vertex(20, 20 + 2 * std::sqrt(75));
	verticesUpper[1] = Vertex(30, 20 + 2 * std::sqrt(75));
	verticesUpper[2] = Vertex(25, 20 + std::sqrt(75));
	verticesLower[0] = Vertex(20, 20);
	verticesLower[1] = Vertex(30, 20);
	verticesLower[2] = verticesUpper[2];

	m_upper = Triangle(verticesUpper);
	m_lower = Triangle(verticesLower);
}


double Hourglass::getArea() const
{
	return (2 * m_lower.getArea());
}

double Hourglass::getPerimeter() const
{
	return (6 * m_len);
}

Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}


void Hourglass::draw(Board& board) const
{
	cout << "drawing" << endl;
	m_upper.draw(board);
	m_lower.draw(board);
}


bool Hourglass::scale(double factor)
{
	return m_upper.scale(factor) && m_lower.scale(factor);
}

Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_len, std::abs(m_height));
}
