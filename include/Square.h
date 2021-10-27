#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"

#include <iostream>
#include <cmath>

class Square
{
public:
	//===--- constructors ---===//
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);
	
	//===--- functions ---===//
	Vertex getBottomLeft()const;
	Vertex getTopRight()const;
	double getLength()const;

	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea()const;
	double getPerimeter()const;
	Vertex getCenter() const;
	bool scale(double factor);

private:
	//members	
	Rectangle m_square;
};
