#pragma once

#include "Vertex.h"
#include "Triangle.h"
#include "macros.h"
#include "Board.h"

class Hourglass {
public:
	Hourglass(const Triangle& upper, const Triangle& lower); //for sure received valid traingles
	Hourglass(const Triangle& lower);
	double getLength() const;
	double getHeight() const;
	//getBoundingRectangle?
	void draw(Board& board);
	double getArea();
	double getPerimeter();
	Vertex getCenter();
	bool scale(double factor);
private:
	Triangle m_upper;
	Triangle m_lower;
	double m_len;
	double m_height;
	void setDefault();
};

