#pragma once

#include "Figure.h"
class Ellipsis :public Figure {

	DECLARE_SERIAL(Ellipsis)   

public:
	Ellipsis() {}
	Ellipsis(CPoint p1, CPoint p2, const COLORREF color, const COLORREF pencolor, int width);
	void Draw(CDC* dc) const;
};

