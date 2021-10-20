#pragma once
#include "framework.h"

class Figure : public CObject {

	DECLARE_SERIAL(Figure)  
	CPoint P1;//first x,y coordinate
	CPoint P2;//last x,y coordinate
	COLORREF Mycolor = 0;//inside color rgb
	COLORREF penColor = 0;//outline color rgb
	CBrush Mybrush; //brush object
	CPen MyPen; //pen object
	int pen_width = 1;//default pen width

public:

	Figure() { }//default constructor must for serialization
	//constructor
	Figure(CPoint p1, CPoint p2,const COLORREF color,const COLORREF pencolor,int width) 
		: P1(p1), P2(p2)
	{
		penColor = pencolor;
		pen_width = width;
		MyPen.CreatePen(PS_SOLID, pen_width, pencolor);// creates pen
		Mycolor = color;
		Mybrush.CreateSolidBrush(Mycolor);//creates brush
	}

	void Serialize(CArchive& ar);//save function

	virtual void Draw(CDC* dc) const
	{
		dc->SelectObject(Mybrush);//receives brush
		dc->SelectObject(MyPen);//receives pen
		dc->Rectangle(P1.x, P1.y, P2.x, P2.y); //draws rectangle
	}

	CPoint getP1() const
	{
		return P1;
	}
	CPoint getP2() const
	{
		return P2;
	}
	CBrush& getMybrush() { return Mybrush; }

	virtual void Redefine(CPoint p1, CPoint p2) { P1 = p1; P2 = p2; }//changes p1,p2 by given coordinates
	virtual bool isInside(const CPoint& P) const;//is point inside shape
	virtual void SetPosition(int dx, int dy);//moves object to specified point
};
