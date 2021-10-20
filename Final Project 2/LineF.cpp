#include "pch.h"
#include "LineF.h"

LineF::LineF(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width) :Figure(p1, p2, color, pencolor, width)
{
}

void LineF::Draw(CDC* dc)const
{
	dc->SelectObject(MyPen);
	dc->MoveTo(P1);
	dc->LineTo(P2);
}
