#pragma once
#include "Vertex.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height); //vertices of line that is paralled to x axis
	Vertex getVertex(int index) const; //returns vertex of index given
	double getLength() const;
	double getHeight() const;

private:
};

Triangle::Triangle(const Vertex vertices[3])
{
	//(1) check that values of vertices are valid (macros)
	//(2) check that first 2 vertices create a line parallel to x axis
	//(3) check that it is an equilateral triangle
	//if 1 2 or 3 are false, create default
}

Triangle :: Triangle(const Vertex& v0, const Vertex& v1, double height);
{
	//(1) check that values of vertices and height are valid (macros)
	//^height is length, send calculated vertex?
	//(2) check that first 2 vertices create a line parallel to x axis
	//(3) check that it is an equilateral triangle 
	//if 1 2 or 3 are false, create default
	//HEIGHT CAN BE NEGATIVE
}

Triangle :: Vertex getVertex(int index) const
{
	//returns vertex of index given
}

Triangle :: double getLength() const
{
	//returns length of side in triangle
}

Triangle :: double getHeight() const
{
	//returns length of height in triangle
	//line perpendicular to base of triangle
}