#pragma once

#include "Vertex.h"
#include "Board.h"
#include "Rectangle.h"
#include "Utilities.h"
#include "Utilities.h"

class Square
{
public:
	Square(const Vertex& bottomLeft, const Vertex& topRight);
	Square(const Vertex& start, double length);
	
	//===--- functions ---===//
  //return BL vertex
	Vertex getBottomLeft()const;
	//return TR vertex
	Vertex getTopRight()const;
	//return width (Xr - Xl)
	double getLength()const;


	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea()const;
	double getPerimeter()const;
	Vertex getCenter() const;
	bool scale(double factor);


private:
	//members
	const int DEFAULT_LEN = 10;
	Rectangle m_square;
};
