
// Final Project 2Dlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Final Project 2.h"
#include "Final Project 2Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CFinalProject2Dlg dialog



CFinalProject2Dlg::CFinalProject2Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FINALPROJECT2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFinalProject2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, Color_change_btn);
	DDX_Control(pDX, IDC_Pen_Color_btn, Pen_color_change_btn);
}

BEGIN_MESSAGE_MAP(CFinalProject2Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_RECTANGLE, &CFinalProject2Dlg::OnBnClickedRectangle)
	ON_BN_CLICKED(IDC_ELLIPSIS, &CFinalProject2Dlg::OnBnClickedEllipsis)
	ON_BN_CLICKED(IDC_Save, &CFinalProject2Dlg::OnBnClickedSave)
	ON_BN_CLICKED(IDC_Load, &CFinalProject2Dlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_Undo, &CFinalProject2Dlg::OnBnClickedUndo)
	ON_BN_CLICKED(IDC_Magen_David, &CFinalProject2Dlg::OnBnClickedMagenDavid)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_Square, &CFinalProject2Dlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_LINEF_BTN, &CFinalProject2Dlg::OnBnClickedLinefBtn)
	ON_BN_CLICKED(IDC_DrawBtn, &CFinalProject2Dlg::OnBnClickedDrawbtn)
	ON_BN_CLICKED(IDC_MoveButton, &CFinalProject2Dlg::OnBnClickedMovebutton)
	ON_BN_CLICKED(IDC_size_1_btn, &CFinalProject2Dlg::OnBnClickedsize1btn)
	ON_BN_CLICKED(IDC_size_2_btn, &CFinalProject2Dlg::OnBnClickedsize2btn)
	ON_BN_CLICKED(IDC_size_3_btn, &CFinalProject2Dlg::OnBnClickedsize3btn)
	ON_BN_CLICKED(IDC_size_4_btn, &CFinalProject2Dlg::OnBnClickedsize4btn)
	ON_BN_CLICKED(IDC_size_5_btn, &CFinalProject2Dlg::OnBnClickedsize5btn)
END_MESSAGE_MAP()


// CFinalProject2Dlg message handlers

BOOL CFinalProject2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CheckRadioButton(IDC_RECTANGLE, IDC_LINEF_BTN, IDC_RECTANGLE);
	CheckRadioButton(IDC_size_1_btn, IDC_size_5_btn, IDC_size_1_btn);

	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFinalProject2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);// device context for painting

		for (int i = 0; i < figs.GetSize(); i++) {
		
			figs[i]->Draw(&dc);
	
		}

		if (isPressed)
		{
			currEdit->Draw(&dc);

		}

		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFinalProject2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CFinalProject2Dlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	start = point;
	if (Mode == 0)//draw
	{
		isPressed = true;
		COLORREF newshapeColor = Color_change_btn.GetColor();
		COLORREF newPenColor = Pen_color_change_btn.GetColor();
		switch (futureFigureKind)
		{
		case 1:
			currEdit = new RectangleF(start, start, newshapeColor,newPenColor, dialog_pen_width);
			break;
		case 2:
			currEdit = new Ellipsis(start, start, newshapeColor, newPenColor, dialog_pen_width);
			break;
		case 3:
			currEdit = new MagenDavid(start, start, newshapeColor, newPenColor, dialog_pen_width);
			break;
		case 4:
			currEdit = new Square(start, start, newshapeColor, newPenColor, dialog_pen_width);
			break;
		case 5:
			currEdit = new LineF(start, start, newshapeColor, newPenColor, dialog_pen_width);
			break;
		}
	}

	else// move
	{
		isPressed = true;
		for (int i = figs.GetSize() - 1; i >= 0; i--)
			if (figs[i]->isInside(start)) {
				CurrMovingFig = true;
				movingFig = i;
				break;
				
			}
				
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}

void CFinalProject2Dlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default

	if (Mode == 0)//draw
	{

		end = point;
		isPressed = false;
		currEdit->Redefine(start, end);
		figs.Add(currEdit);
		currEdit = NULL;
		Invalidate(); //simulates the WM_PAINT message to redraw window
	}

	else if (Mode == 1 && CurrMovingFig)//move
	{
		end = point;
		isPressed = false;
		figs[movingFig]->SetPosition(end.x, end.y);
		CurrMovingFig = false;
		Invalidate();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}

void CFinalProject2Dlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (isPressed)
	{
		if (Mode == 0)
		{
			end = point;
			currEdit->Redefine(start, end);
			Invalidate(); //simulates the WM_PAINT message to redraw window
		}

	}
	CDialogEx::OnMouseMove(nFlags, point);
}



void CFinalProject2Dlg::OnBnClickedRectangle()
{
	futureFigureKind = 1;
}


void CFinalProject2Dlg::OnBnClickedEllipsis()
{
	futureFigureKind = 2;
}

void CFinalProject2Dlg::OnBnClickedMagenDavid()
{
	futureFigureKind = 3;
}

void CFinalProject2Dlg::OnBnClickedSquare()
{
	futureFigureKind = 4;
}

void CFinalProject2Dlg::OnBnClickedLinefBtn()
{
	futureFigureKind = 5;
}




void CFinalProject2Dlg::OnBnClickedSave()
{
	// FALSE to SAVE
	CFileDialog dlg(FALSE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeCreate | CFile::modeWrite);
		CArchive ar(&file, CArchive::store);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
	}
}


void CFinalProject2Dlg::OnBnClickedLoad()
{
	// TRUE to LOAD
	CFileDialog dlg(TRUE, _T(".figs"), NULL, 0, _T("Figures (*.figs)|*.figs|All Files (*.*)|*.*||"));
	CString filename;
	if (dlg.DoModal() == IDOK)
	{
		filename = dlg.GetPathName(); // return full path and filename
		CFile file(filename, CFile::modeRead);
		CArchive ar(&file, CArchive::load);
		figs.Serialize(ar);
		ar.Close();
		file.Close();
		Invalidate();
	}
}


void CFinalProject2Dlg::OnBnClickedUndo()
{
	if (figs.GetSize() > 0) {
		figs.RemoveAt(figs.GetSize() - 1);
		Invalidate();
	}
}


void CFinalProject2Dlg::OnBnClickedDrawbtn()
{
	// TODO: Add your control notification handler code here
	Mode = 0;
}


void CFinalProject2Dlg::OnBnClickedMovebutton()
{
	Mode = 1;
}


void CFinalProject2Dlg::OnBnClickedsize1btn()
{
	dialog_pen_width = 1;
}


void CFinalProject2Dlg::OnBnClickedsize2btn()
{
	dialog_pen_width = 2;
}


void CFinalProject2Dlg::OnBnClickedsize3btn()
{
	dialog_pen_width = 3;
}


void CFinalProject2Dlg::OnBnClickedsize4btn()
{
	dialog_pen_width = 4;
}


void CFinalProject2Dlg::OnBnClickedsize5btn()
{
	dialog_pen_width = 5;
}
