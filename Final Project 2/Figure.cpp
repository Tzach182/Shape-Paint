#include "pch.h" 
#include "Figure.h"


IMPLEMENT_SERIAL(Figure, CObject, 1)


void Figure::Serialize(CArchive& ar)
{
	CObject::Serialize(ar); // calls father functions
	if (ar.IsStoring()) //storing
	{
		ar << P1;
		ar << P2;
		ar << Mycolor;
		ar << penColor;
		ar << pen_width;
	}
	else // Loading, not storing
	{
		ar >> P1;
		ar >> P2;
		ar >> Mycolor;
		ar >> penColor;
		ar >> pen_width;
		Mybrush.CreateSolidBrush(Mycolor);
		MyPen.CreatePen(PS_SOLID, pen_width, penColor);
	}
}


bool Figure::isInside(const CPoint& P) const
{
	return (P1.x <= P.x && P.x <= P2.x || P1.x >= P.x && P.x >= P2.x) &&
		(P1.y <= P.y && P.y <= P2.y || P1.y >= P.y && P.y >= P2.y);
}
void Figure::SetPosition(int dx, int dy)
{
	int diffX = abs(P1.x - P2.x);//saves the difference between the two points
	int diffY = abs(P1.y - P2.y);

	P1 = CPoint(dx, dy);
	P2 = CPoint(P1.x+diffX,P1.y+diffY);
}
