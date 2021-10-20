#include "pch.h"
#include "Ellipsis.h"

IMPLEMENT_SERIAL(Ellipsis, CObject, 1)

Ellipsis::Ellipsis(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width):Figure(p1,p2,color,pencolor,width)
{
}

void Ellipsis::Draw(CDC* dc) const
{
	CPoint p1 = getP1();
	CPoint p2 = getP2();
	dc->SelectObject(Mybrush);
	dc->SelectObject(MyPen);
	dc->Ellipse(p1.x, p1.y, p2.x, p2.y);
}
