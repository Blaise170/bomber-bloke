You need to include WINGSTUF.H and WING.H and you need to add
WING32.LIB and WINGSTUF.C to the project.  The project must be
compiled for Win32.  You need to also include the owl library
"owl\gdiobjec.h".

In the private section of the main window class, declare


	HINSTANCE h;  // used as shorthand for GetApplication()->GetInstance();
	HDC MemDc;    // holds a WinG Device Context
	void far* MemDcBits;   // Points to the beginning of the Device Context
	TPalette* Pal;


In the SetupWindow function of the main window class, put

h=GetApplication()->GetInstance();
TDib* Sprite=new TDib(h, RESOURCE_ID);
Pal=new TPalette(*Sprite);
MemDc=CreateWinGDC(Sprite->GetColors(), &MemDcBits);
delete Sprite

Sprite is used temporarily to set up the palette.

This has initialised everything.

In the Paint function you will want to blt the MemDc to the screen, so
you put

void
TBombBlokeWin::Paint(TDC& dc, BOOL, TRect&)
{
	dc.SelectObject(*Pal);
	dc.RealizePalette();
	TRect r=GetClientRect();
	int CX=r.right-r.left;
	int CY=r.bottom-r.top;
	WinGBitBlt((HDC)dc, 0, 0, CX, CY, MemDc, 0, 0);
}

Notice that the palette is remapped to be safe.
This gives the program definite priority when its main window has the
input focus.

To draw to the MemDc, you can blt TDibs to it, like

TDib* Wall;
Wall=new TDib(h, RESOURCE_ID);
DibXy(MemDcBits, X, Y, Wall);
delete Wall;

Then, you would invalidate to call the paint function

InvalidateRect(x, y, x2, y2);

You can have as many WinG Device contexts as you can fit in memory
and then you can use WinGBitBlt to blt one to the other.  For example,
you could keep any fixed background objects in one dc and then at every
game cycle you could blt this DC to a second dc and add the movable objects.
The WinG Dc that gets blted to the screen depends on the contents of the
Paint function.

The Rival Graphics Library Routines

DibXY






