#include <stdio.h>
#include <stdlib.h>
#include "getkey.h"
#include "bbloke.rh"

char Dirs[5][20]={"Drop", "Left", "Right", "Up", "Down"};
char Cols[4][20]={"Red", "Green", "Blue", "Purple"};

TGetKeyDialog::TGetKeyDialog(TWindow* parent, uint* Keys)
 : TWindow(parent, "Configure Keys")
{
	KeyHolder=Keys;
	Bloke=0;
	Key=0;
}

void
TGetKeyDialog::SetupWindow()
{
	TWindow::SetupWindow();
	sprintf(s, "Press %s key for %s player", Dirs[Key], Cols[Bloke]);
	SetCaption(s);
}

void
TGetKeyDialog::EvKeyDown(uint Key, uint, uint f)
{
	 if ((f&16384)==0) {
		KeyHolder[Bloke*5+Key]=Key;
		Key++;
		if (Key==5) {
			Bloke++;
			if (Bloke==4) {
            CloseWindow();
			}
		}
		sprintf(s, "Press %s key for %s player", Dirs[Key], Cols[Bloke]);
	   SetCaption(s);
	 }
}

BOOL
TGetKeyDialog::CanClose()
{
	TWindow::CanClose();
	return TRUE;
}

TGetKeyDialog::~TGetKeyDialog()
{
}

DEFINE_RESPONSE_TABLE1(TGetKeyDialog, TWindow)
	EV_WM_KEYDOWN,
END_RESPONSE_TABLE;

