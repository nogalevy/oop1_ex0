#include "Triangle.h"

#include <iostream>
// -----================ constructors ================-----
//----

Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{
	/*
	std::cout << "IF :\n";
	std::cout << "v0 is valid: " << m_v0.isValid() << "\n";
	std::cout << "v1 is valid: " << m_v1.isValid() << "\n";
	std::cout << "v2 is valid: " << m_v2.isValid() << "\n";
	std::cout << "is 0 1 sameRow " << sameRow(m_v0, m_v1) << "\n";
	std::cout << "v1 isToTheRightOf v0: " << m_v1.isToTheRightOf(m_v0) << "\n";
	std::cout << "len == v1 t0 v2 " << doubleEqual(getLength(), distance(m_v1, m_v2)) << "\n";
	std::cout << "len == v0 t0 v2 " << doubleEqual(getLength(), distance(m_v0, m_v2)) << "\n";
	std::cout << "length: " << getLength() << "\n";
	std::cout << "v0 to v2: " << distance(m_v0, m_v2) << "\n";*/
	
	
	if (!(m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& sameRow(m_v0, m_v1) && m_v1.isToTheRightOf(m_v0)))
		//&& doubleEqual(getLength(), distance(m_v1, m_v2))
		//&& doubleEqual(getLength(), distance(m_v0, m_v2))))
		setDefault();
}

//----
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	:m_v0(v0), m_v1(v1), m_v2(Vertex((m_v1.m_col - m_v0.m_col) / 2, m_v0.m_row + height))
{
	if (!(m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& sameRow(m_v0, m_v1) && m_v1.isToTheRightOf(m_v0)
		&& doubleEqual(distance(m_v0, m_v2), distance(m_v1, m_v0))))
			setDefault();
	
}

// -----================ main functions (public) ================-----
//----
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

//----
double Triangle::getLength() const
{
	return distance(m_v0, m_v2);
	//return (m_v1.m_col - m_v0.m_col);
}

//----
double Triangle::getHeight() const
{
	return (m_v2.m_row - m_v0.m_row);
}

//----
void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v0, m_v2);
}

//----
double Triangle::getArea() const
{
	return abs((getLength() * getHeight()) / 2);
}

//----
double Triangle::getPerimeter() const
{
	return (3 * getLength());
}

//----
Vertex Triangle::getCenter() const
{
	return Vertex((m_v0.m_col + m_v1.m_col + m_v2.m_col) / 3,
		(m_v0.m_row + m_v1.m_row + m_v2.m_row) / 3);
}

//----
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

//----
Rectangle Triangle::getBoundingRectangle() const
{
	if (getHeight() < 0)
		return Rectangle(Vertex(m_v0.m_col, m_v2.m_row), m_v1);

	return Rectangle(m_v0, Vertex(m_v1.m_col, m_v2.m_row));
}


// -----================ sub functions (private) ================-----
//----

void Triangle::setDefault()
{
	m_v0 = Vertex(20, 20);
	m_v1 = Vertex(30, 20);
	m_v2 = Vertex(25, 20 + sqrt(7));
}


/*
Triangle::Triangle(const Vertex vertices[3])
	:m_v0(vertices[0]), m_v1(vertices[1]), m_v2(vertices[2])
{
	if (!(vertices[0].isValid() && vertices[1].isValid() && vertices[2].isValid()
		&& sameRow(vertices[0], vertices[1]) && vertices[1].isToTheRightOf(vertices[0])
		&& doubleEqual(distance(vertices[0], vertices[1]), distance(vertices[1], vertices[2])) //took out asama to len
		&& doubleEqual(distance(vertices[1], vertices[2]), distance(vertices[2], vertices[0]))))
	{
		setDefault();
		//m_v0 = vertices[0];
		//m_v1 = vertices[1];
		//m_v2 = vertices[2];

		//m_height = calcHeight();
	}

	//else
		//setDefault();
}

//----
Triangle::Triangle(const Vertex& v0, const Vertex& v1, double height)
	//:m_v0(v0), m_v1(v1), m_height(height), m_len(m_v0.m_col + m_v1.m_col), m_v2((m_v0.m_col + m_v1.m_col) / 2, m_v0.m_row + height)
	:m_v0(v0), m_v1(v1), m_v2((m_v1.m_col - m_v0.m_col) / 2, m_v0.m_row + height)
{
	if (!(m_v0.isValid() && m_v1.isValid() && m_v2.isValid()
		&& sameRow(m_v0, m_v1) && m_v1.isToTheRightOf(m_v0)
		&& doubleEqual(distance(m_v0, m_v2), distance(m_v1, m_v0))))
	{
		setDefault();
		/*m_len = distance(v0, v1);
		m_v2.m_col = v0.m_col + (m_len / 2);
		m_v2.m_row = v0.m_row + height;

		
		if (m_v2.isValid()
			&& doubleEqual(distance(m_v0, m_v2), distance(m_v1, m_v0)))
		{
			//m_v0 = v0;
			//m_v1 = v1;

			return;
		}
		
	}


}

// -----================ main functions (public) ================-----
//----
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

//----
double Triangle::getLength() const
{
	//return m_len;
	return distance(m_v0, m_v1);
}

//----
double Triangle::getHeight() const
{
	//return m_height;
	return (m_v2.m_row - m_v0.m_row);
}

//----
void Triangle::draw(Board& board) const
{
	board.drawLine(m_v0, m_v1);
	board.drawLine(m_v1, m_v2);
	board.drawLine(m_v0, m_v2);
}

//----
double Triangle::getArea() const
{
	//return std::abs((m_len * m_height) / 2);
	return std::abs((getLength() * getHeight()) / 2);
}

//----
double Triangle::getPerimeter() const
{
	//return (3 * m_len);
	return (3 * getLength());
}

//----
Vertex Triangle::getCenter() const
{
	return Vertex((m_v0.m_col + m_v1.m_col + m_v2.m_col) / 3,
		(m_v0.m_row + m_v1.m_row + m_v2.m_row) / 3);
}

//----
bool Triangle::scale(double factor)
{

	if (factor <= 0)
		return false;

	Vertex center = getCenter();
	Vertex new_v0, new_v1, new_v2;

	//if (m_height > 0)
	if (getHeight() > 0)
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


	if (!new_v0.isValid() || !new_v1.isValid() || !new_v2.isValid())
		return false;

	m_v0 = new_v0;
	m_v1 = new_v1;
	m_v2 = new_v2;

	//m_height = calcHeight();
	//m_len = distance(m_v0, m_v1);

	return true;
}

//----
Rectangle Triangle::getBoundingRectangle() const
{
	//if (m_height < 0)
	//if(getHeight() < 0)
		//return Rectangle(Vertex(m_v0.m_col, m_v2.m_row), getLength(), std::abs(getHeight()));

	//return Rectangle(m_v0, getLength(), getHeight());
	if (getHeight() < 0)
		return Rectangle(Vertex(m_v0.m_col, m_v2.m_row), m_v1);

	return Rectangle(m_v0, Vertex(m_v1.m_col, m_v2.m_row));
}


// -----================ sub functions (private) ================-----
//----

double Triangle::calcHeight()
{
	Vertex midpoint(m_v2.m_col, m_v0.m_row);

	return distance(m_v2, midpoint);
}

//----
void Triangle::setDefault()
{
	m_v0 = Vertex(20, 20);
	m_v1 = Vertex(30, 20);
	m_v2 = Vertex(25, 20 + std::sqrt(7));

	//m_len = distance(m_v0, m_v1);
	//m_height = calcHeight();
}
*/