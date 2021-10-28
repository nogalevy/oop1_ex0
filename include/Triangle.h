#pragma once
#include "Vertex.h"
#include "Utilities.h"
#include <cmath>
#include "Board.h"
#include "Rectangle.h"

/*
class Triangle {
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
	double m_len;
	double m_height;

	//sub functions
	double calcHeight();
	void setDefault();
};
*/

class Triangle {
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