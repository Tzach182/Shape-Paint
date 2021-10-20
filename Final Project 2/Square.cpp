#include "pch.h"
#include "Square.h"

IMPLEMENT_SERIAL(Square,CObject,1)


Square::Square(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width) :RectangleF(p1, p2, color, pencolor, width)
{
}

void Square::Draw(CDC* dc)const
{
	CPoint center = P1 + P2;
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(P1.x - P2.x) < abs(P1.y - P2.y) ? abs(P1.x - P2.x) / 2.0 : abs(P1.y - P2.y) / 2.0;
	dc->SelectObject(Mybrush);
	dc->SelectObject(MyPen);
	dc->Rectangle(center.x-radius, center.y - radius, center.x + radius, center.y + radius);
}
