#include "pch.h"
#include "RectangleF.h"


IMPLEMENT_SERIAL(RectangleF, CObject, 1)


RectangleF::RectangleF(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width) :
	Figure(p1, p2, color, pencolor, width)
{
}
