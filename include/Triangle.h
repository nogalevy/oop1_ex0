#pragma once
#include "Vertex.h"
#include "Utilities.h"
#include <cmath> //needed? 
#include "Board.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height); //vertices of line that is paralled to x axis
	Vertex getVertex(int index) const; //returns vertex of index given
	double getLength() const;
	double getHeight() const;
	void draw(Board& board);
	double getArea();
	double getPerimeter();
	Vertex getCenter();
	bool scale(double factor);


private:
	Vertex m_v0;
	Vertex m_v1;
	Vertex m_v2;
	double m_len;
	double m_height;
	double calcHeight();
	void setDefault();
};

void Triangle::draw(Board& board)
{

}

double Triangle::getArea()
{
	return (m_len * m_height) / 2;
}

double Triangle::getPerimeter()
{
	return 3 * m_len;
}

Vertex Triangle::getCenter()
{

}

bool Triangle::scale(double factor)
{

}