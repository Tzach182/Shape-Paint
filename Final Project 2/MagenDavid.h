#pragma once
#include "RectangleF.h"

class MagenDavid: public RectangleF
{
	DECLARE_SERIAL(MagenDavid)

public:
	MagenDavid() {};
	MagenDavid(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width);
	void Draw(CDC* dc)const;
};

