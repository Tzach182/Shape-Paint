
// Final Project 2Dlg.h : header file
//

#pragma once

#include "Figure.h"
#include "RectangleF.h"
#include "Ellipsis.h"
#include "MagenDavid.h"
#include "Square.h"
#include "LineF.h"



// CFinalProject2Dlg dialog
class CFinalProject2Dlg : public CDialogEx
{
// Construction
public:
	CFinalProject2Dlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FINALPROJECT2_DIALOG };
#endif
	CPoint start, end;//p1,p2
	bool isPressed = false;//left mouose button pressed-true,not pressed false
	Figure* currEdit; // a temp for each figure
	CTypedPtrArray< CObArray, Figure*> figs;//polymorphic array of figures
	int futureFigureKind = 1; //Rectangle /2 - Ellipse / 3 - Magen david /4 - square /5 - line
	int Mode = 0;//0=draw,1=move
	bool CurrMovingFig = false;//flage to know if a figure is moving
	int movingFig = 0; // which figure is moving
	int dialog_pen_width = 1;//size of outline by radio button

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnBnClickedEllipsis();
	afx_msg void OnBnClickedSave();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedUndo();
	afx_msg void OnBnClickedMagenDavid();
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedLinefBtn();
	afx_msg void OnBnClickedDrawbtn();
	afx_msg void OnBnClickedMovebutton();
	afx_msg void OnBnClickedsize1btn();
	afx_msg void OnBnClickedsize2btn();
	afx_msg void OnBnClickedsize3btn();
	afx_msg void OnBnClickedsize4btn();
	afx_msg void OnBnClickedsize5btn();

public:
	CMFCColorButton Color_change_btn;
	CMFCColorButton Pen_color_change_btn;
	
};
