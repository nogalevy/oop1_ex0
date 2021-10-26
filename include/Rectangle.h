#pragma once
#include "Utilities.h"

#include "Vertex.h"
#include "Board.h"

const int DEFAULT_LEN = 10;

class Rectangle
{
public:
	//===--- constructors ---===//
	
	Rectangle(const Vertex& bottomLeft, const Vertex& topRight);
	
	Rectangle(const Vertex vertices[2]);
	
	Rectangle(double x0, double y0, double x1, double y1);
	
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
	//
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
