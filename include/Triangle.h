#pragma once
#include "Vertex.h"
#include "Utilities.h"

class Triangle {
public:
	Triangle(const Vertex vertices[3]);
	Triangle(const Vertex& v0, const Vertex& v1, double height); //vertices of line that is paralled to x axis
	Vertex getVertex(int index) const; //returns vertex of index given
	double getLength() const;
	double getHeight() const;

private:
	Vertex m_v0;
	Vertex m_v1;
	Vertex m_v2;
	double m_len;
	double m_height;
	double calcHeight();
	void setDefault();
};


