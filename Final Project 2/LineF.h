#pragma once
#include"Figure.h"

class LineF:public Figure
{
public:
	LineF(){}
	LineF(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width);
	void Draw(CDC* dc)const;
};

