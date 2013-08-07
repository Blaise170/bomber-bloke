#include <owl\applicat.h>
#include <owl\framewin.h>
#include <owl\dc.h>
#include <owl\gdiobjec.h>
#include <\bomb\bbloke.rh>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <wing.h>
#include "wingstuf.h"

class TBombBlokeWin : public TWindow
{
	public:
	  TBombBlokeWin();
	  ~TBombBlokeWin();
  protected:
	 void SetupWindow();
	 void EvTimer(uint TimerId);
	 virtual void Paint(TDC& dc, BOOL erase, TRect& rect);
	 void CmStart();
  DECLARE_RESPONSE_TABLE(TBombBlokeWin);
};

TBombBlokeWin::TBombBlokeWin() : TWindow(0, 0, 0)
{
}

void
TBombBlokeWin::SetupWindow() {
  TWindow::SetupWindow();
}

TBombBlokeWin::~TBombBlokeWin()
{
}

void
TBombBlokeWin::Paint(TDC& dc, BOOL, TRect&)
{
	dc.SelectObject(*BombBlokePalette);
	dc.RealizePalette();
	TRect r=GetClientRect();
	int CX=r.right-r.left;
	int CY=r.bottom-r.top;
	WinGBitBlt((HDC)dc, 0, 0, CX, CY, MemDc, 0, 0);
}
									  
void
TBombBlokeWin::EvTimer(uint TimerId)
{
}

class TBombBlokeApp : public TApplication
{
	public:
	  TBombBlokeApp(char far* name) : TApplication(name) {};
	  void InitMainWindow();
	  TFrameWindow* Frame;
};

void
TBombBlokeWin::CmStart()
{
}

void
TBombBlokeApp::InitMainWindow()
{
	TBombBlokeWin& Client=*new TBombBlokeWin;
	Frame=new TFrameWindow(0, "Bomb Bloke", &Client);
	SetMainWindow(Frame);
	Frame->AssignMenu(MENU_1);

// **************************************************************
// To set up main window could also use...
// **************************************************************
// SetMainWindow(new TBombBlokeWin(0, "Bomb Bloke"));
// **************************************************************
// You would need to define window class as
// class TBombBlokeWin : public TFrameWindow {
//   public:
//      TBombBlokeWin(TWindow* parent, const far char* title);
// }
//
// TBombBlokeWin::TBombBlokeWin(TWindow* parent, const far char* title)
//    : TFrameWindow(parent, title)
//    : TWindow(parent, title)
// {
//     AssignMenu(MENU_1);
// }
// **************************************************************
// Menu is assigned in window constructor.
// **************************************************************
}

DEFINE_RESPONSE_TABLE1(TBombBlokeWin, TWindow)
  EV_COMMAND(CM_START, CmStart),
  EV_WM_TIMER,
END_RESPONSE_TABLE;

int
OwlMain(int, char* [])
{
	return TBombBlokeApp("Bomb Bloke").Run();
}
