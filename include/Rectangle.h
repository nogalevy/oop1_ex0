	#pragma once

	#include "Utilities.h"
	#include "Vertex.h"
	#include "Board.h"

class Rectangle
{
public:
	//===--- constructors ---===//
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	Rectangle(const Vertex vertices[2]);
	Rectangle(double x0, double y0, double x1, double y1);
	Rectangle(const Vertex& start, double width, double height);

	//===--- functions ---===//
	Vertex getBottomLeft()const;
	Vertex getTopRight()const;
	double getWidth()const;	 // the side : ___
	double getHeight()const; // the side : |
	
	void draw(Board& board)const;
	Rectangle getBoundingRectangle() const;
	double getArea()const;
	double getPerimeter()const;	
	Vertex getCenter() const;
	bool scale(double factor);

private:
	//members
	Vertex m_bottomLeft; 
	Vertex m_topRight; 
	double m_width;
	double m_height;

	//sub functions
	void saveDefault();
	void saveVertices(const Vertex& bottomLeft, const Vertex& topRight);
	bool isRectangleVerticesValid(const Vertex& bottomLeft, const Vertex& topRight);
};
