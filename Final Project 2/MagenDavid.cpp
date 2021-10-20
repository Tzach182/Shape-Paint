#include "pch.h"
#include "MagenDavid.h"

IMPLEMENT_SERIAL(MagenDavid, CObject, 1)

MagenDavid::MagenDavid(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width) 
	:RectangleF(p1, p2, color, pencolor, width)
{
}

void MagenDavid::Draw(CDC* dc) const
{
	CPoint center = P1 + P2;
	center.x /= 2.0; center.y /= 2.0;
	double radius = abs(P1.x - P2.x) < abs(P1.y - P2.y) ? abs(P1.x - P2.x) / 2.0 : abs(P1.y - P2.y) / 2.0;
	CPoint vertices[12];
	double two_pi = atan(1) * 8;
	for (int i = 0; i < 12; i++)
	{
		if (i % 2 == 0)
		{
			vertices[i].x = center.x + radius / sqrt(3) * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius / sqrt(3) * sin(two_pi / 12 * i);
		}
		else
		{
			vertices[i].x = center.x + radius * cos(two_pi / 12 * i);
			vertices[i].y = center.y + radius * sin(two_pi / 12 * i);
		}
	}
	dc->SelectObject(Mybrush);
	dc->SelectObject(MyPen);
	dc->Polygon(vertices, 12);
}
