#pragma once
#include "RectangleF.h"

class Square: public RectangleF
{
	DECLARE_SERIAL(Square)


public:

	Square() {}
	Square(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width);
	virtual void Draw(CDC* dc)const;

};

