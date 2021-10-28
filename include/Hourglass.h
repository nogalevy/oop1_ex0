#pragma once

#include "Vertex.h"
#include "Triangle.h"
#include "macros.h"
#include "Board.h"

class Hourglass 
{
public:
	//===--- constructors ---===//
	Hourglass(const Triangle& upper, const Triangle& lower);
	Hourglass(const Triangle& lower);

	//===--- functions ---===//
	double getLength() const;
	double getHeight() const;
	Rectangle getBoundingRectangle() const;
	void draw(Board& board) const;
	double getArea() const;
	double getPerimeter() const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	//members	
	Triangle m_upper;
	Triangle m_lower;

	//sub functions
	void setDefault();
};