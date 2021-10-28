#pragma once

#include "Vertex.h"
#include "Utilities.h"
#include "Board.h"
#include "Rectangle.h"

#include <cmath>

class Triangle 
{
public:
	//===--- constructors ---===//
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height);

	//===--- functions ---===//
	Vertex getVertex(int index) const;
	double getLength() const;
	double getHeight() const;
	void draw(Board& board) const;
	Rectangle getBoundingRectangle() const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	//members	
	Vertex m_v0;
	Vertex m_v1;
	Vertex m_v2;

	//sub functions
	void setDefault();
};