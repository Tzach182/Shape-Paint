#pragma once
#include "Figure.h"

class RectangleF : public Figure {

	DECLARE_SERIAL(RectangleF)  
public:

	RectangleF() { }
	RectangleF(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width);
	virtual void Draw(CDC* dc) { Figure::Draw(dc); }
};

