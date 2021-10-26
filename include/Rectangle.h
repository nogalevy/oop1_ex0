#pragma once
#include "Utilities.h"

#include "Vertex.h"
#include "Board.h"

class Rectangle
{
public:
	//===--- constructors ---===//
	Rectangle() = delete;
		/*
		gets 2 vertices checks:
		1. if in board
		2. if really is in bottomleft and topright
		when one of the conditions is false - create default rectangle in (20,10) and (30,20)
		*/
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
		/*
		same as the above but get the vertices in array - BL = 0 and TR = 1
		*/
	Rectangle(const Vertex vertices[2]);
		/*
		BL = x0 y0    TR = x1 y1
		also check same as the above
		*/
	Rectangle(double x0, double y0, double x1, double y1);
		/*
		gets BL vertex, width and height
		after create the cordinate check if valid and also check the width,height>0
		if not valid create default rectangle
		*/
	Rectangle(const Vertex& start, double width, double height);

	//===--- functions ---===//
  //return BL vertex
  Vertex getBottomLeft()const;
  //return TR vertex
  Vertex getTopRight()const;
  //return width (Xr - Xl)
  double getWidth()const;
  //return height (Yt - Yb)
  double getHeight()const;
	

  void draw(Board& board)const;
  Rectangle getBoundingRectangle() const;
  double getArea()const;
  double getPerimeter()const;	
  Vertex getCenter() const;
  bool scale(double factor);


private:
	const int DEFAULT_LEN = 10;
	//members

  Vertex m_bottomRight; //bottom right ?
  Vertex m_bottomLeft; //bottom left
  Vertex m_topLeft; //top left ?
  Vertex m_topRight; //top right
  double m_width;
  double m_height;
  //--- sub functions ---
	void saveDefault();
	void saveVertices(const Vertex& bottomLeft, const Vertex& topRight);
};
