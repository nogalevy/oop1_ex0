#include "Hourglass.h"


// -----================ constructors ================-----
//----
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_lower(lower), m_upper(upper)
{
	if (!(doubleEqual(upper.getLength(), lower.getLength())
		&& (verticesEqual(upper.getVertex(2), lower.getVertex(2)))
		&& (upper.getVertex(0).isHigherThan(lower.getVertex(0)))))
		 setDefault();
}

//----
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
//----
double Hourglass::getLength() const
{
	return m_lower.getLength();
}

//----
double Hourglass::getHeight() const
{
	return abs(2 * (m_lower.getHeight()));
}

//----
double Hourglass::getArea() const
{
	return 2 * m_lower.getArea();
}

//----
double Hourglass::getPerimeter() const
{
	return 2 * m_lower.getPerimeter();
}

//----
Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}

//----
void Hourglass::draw(Board& board) const
{
	m_upper.draw(board);
	m_lower.draw(board);
}

//----
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

//----
Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(1));
	//return Rectangle(m_lower.getVertex(0), getLength(), getHeight());
}


// -----================ sub functions (private) ================-----


//----
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



//-----------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------

/*
//----
Hourglass::Hourglass(const Triangle& upper, const Triangle& lower)
	:m_lower(lower), m_upper(upper)
{
	if (doubleEqual(upper.getLength(), lower.getLength())
		&& (verticesEqual(upper.getVertex(2), lower.getVertex(2)))
		&& (upper.getVertex(0).isHigherThan(lower.getVertex(0))))
	{
		m_upper = upper;
		m_lower = lower;
		//m_len = upper.getLength();
		//m_height = 2 * lower.getHeight();
	}
	else setDefault();
}

//----
Hourglass::Hourglass(const Triangle& lower)
	:m_lower(lower), m_upper(lower)
{
	Vertex v0((lower.getVertex(0)).m_col, (lower.getVertex(0)).m_row + 2 * lower.getHeight()),
			v1((lower.getVertex(1)).m_col, (lower.getVertex(1)).m_row + 2 * lower.getHeight());

	if (v0.isValid() && v1.isValid() && sameRow(v0, v1))
	{
		m_lower = lower;
		//m_len = lower.getLength();
		//m_height = 2* lower.getHeight();
		m_upper = Triangle(v0, v1, -lower.getHeight());
	}
	else setDefault();
}

// -----================ main functions (public) ================-----
//----
double Hourglass::getLength() const
{
	//return m_len;
	return m_lower.getLength();
}

//----
double Hourglass::getHeight() const
{
	//-return m_height;
	return 2 * (m_lower.getHeight());
}

//----
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

//----
double Hourglass::getArea() const
{
	return 2 * m_lower.getArea();
}

//----
double Hourglass::getPerimeter() const
{
	return 2 * m_lower.getPerimeter();
}

//----
Vertex Hourglass::getCenter() const
{
	return m_lower.getVertex(2);
}

//----
void Hourglass::draw(Board& board) const
{
	m_upper.draw(board);
	m_lower.draw(board);
}

//----
bool Hourglass::scale(double factor)
{
	if (factor <= 0)
		return false;

	Vertex center = getCenter(),
		new_tl, new_tr, new_bl, new_br;

	double xdiff, ydiff;

	xdiff = factor * (center.m_col - m_upper.getVertex(0).m_col);
	ydiff = factor * (center.m_row - m_upper.getVertex(0).m_row);

	new_bl = Vertex(center.m_col - xdiff, center.m_row - ydiff);
	new_br = Vertex(new_tr.m_col + xdiff, center.m_row - ydiff);
	new_tl = Vertex(center.m_col - xdiff, center.m_row + ydiff);
	new_tr = Vertex(center.m_col + xdiff, center.m_row + ydiff);

	if (!new_tl.isValid() || !new_tr.isValid() || !new_bl.isValid() || !new_br.isValid())
		return false;

	//m_height = new_tl.m_row - new_bl.m_row;
	//m_len = distance(new_tl, new_tr);

	m_upper = Triangle(new_tl, new_tr, center.m_row - new_tl.m_row);
	m_lower = Triangle(new_bl, new_br, center.m_row - new_bl.m_row);

	return true;
}

//
////----
//bool Hourglass::scale(double factor)
//{
//
//	if (factor <= 0)
//		return false;
//
//	Vertex top_left = m_upper.getVertex(0),
//		top_right = m_upper.getVertex(1),
//		bottom_left = m_lower.getVertex(0),
//		bottom_right = m_lower.getVertex(1),
//		center = m_lower.getVertex(2),
//		new_tl, new_tr, new_bl, new_br;
//
//	int xdiff, ydiff;
//
//	xdiff = factor * (center.m_col - top_left.m_col);
//	ydiff = factor * (top_left.m_row - center.m_row);
//
//	new_tl = Vertex(center.m_col - xdiff, center.m_row + ydiff);
//	new_tr = Vertex(center.m_col + xdiff, new_tl.m_row);
//	new_bl = Vertex(new_tl.m_col, center.m_row - ydiff);
//	new_br = Vertex(new_tr.m_col, new_bl.m_row);
//
//	//new_tl = Vertex(center.m_col - (center.m_col - top_left.m_col) * factor, center.m_row + (top_left.m_row - center.m_row) * factor);
//	//new_tr = Vertex(center.m_col + (top_right.m_col - center.m_col) * factor, new_tl.m_row);
//	//new_bl = Vertex(center.m_col - (center.m_col - bottom_left.m_col) * factor, center.m_row - (center.m_row - bottom_left.m_row) * factor);
//	//new_br = Vertex(center.m_col + (bottom_left.m_col - center.m_col) * factor, new_bl.m_row);
//
//	if (!new_tl.isValid() || !new_tr.isValid() || !new_bl.isValid() || !new_br.isValid())
//		return false;
//
//	//m_height = distance(new_tl, new_bl);
//	m_height = new_tl.m_row - new_bl.m_row;
//	m_len = distance(new_tl, new_tr);
//
//	Vertex new_vertices1[3] = { new_tl, new_tr, center },
//		new_vertices2[3] = { new_bl, new_br, center };
//
//	//m_lower = Triangle(new_bl, new_br, (m_height /2 ));
//	//m_upper = Triangle(new_tl, new_tr, (-1 * (m_height / 2)));
//
//	m_upper = Triangle(new_vertices1);
//	m_lower = Triangle(new_vertices2);
//
//
//
//
//	return true;
//
//
//}

//----
Rectangle Hourglass::getBoundingRectangle() const
{
	return Rectangle(m_lower.getVertex(0), m_upper.getVertex(1));
}

*/