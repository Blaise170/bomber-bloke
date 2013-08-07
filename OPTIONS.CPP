#include <stdio.h>
#include <stdlib.h>
#include "options.h"
#include "getkey.h"
#include "bbloke.rh"

TOptionsDialog::TOptionsDialog(TWindow* parent, OptionsStruct* Options, uint* Keys)
  : TDialog(parent, OPTIONS)
{
	Red=new TComboBox(this, IDC_RED);
	Green=new TComboBox(this, IDC_GREEN);
	Blue=new TComboBox(this, IDC_BLUE);
	Purple=new TComboBox(this, IDC_PURPLE);
	Style=new TComboBox(this, IDC_STYLE);
	Order=new TComboBox(this, IDC_ORDER);
	Games=new TEdit(this, IDC_GAMES);
	MazeNumber=new TEdit(this, IDC_MAZENUMBER);
	MegaRiot=new TEdit(this, IDC_MEGARIOT);
	WorkingOptions=Options;
	KeyBloke=-1;
	KeyHolder=Keys;
}

void
TOptionsDialog::SetupWindow()
{
	TDialog::SetupWindow();
	sprintf(s, "%02i", WorkingOptions->Games);
	Games->SetText(s);
	sprintf(s, "%02i", WorkingOptions->MazeNumber);
	MazeNumber->SetText(s);
	sprintf(s, "%02i", WorkingOptions->MegaRiot);
	MegaRiot->SetText(s);
	Red->ClearList();
	Red->InsertString("Computer", -1);
	Red->InsertString("Keyboard", -1);
	Red->InsertString("Joystick", -1);
	Red->SetSelIndex(WorkingOptions->Red);
	Green->ClearList();
	Green->InsertString("Computer", -1);
	Green->InsertString("Keyboard", -1);
	Green->InsertString("Joystick", -1);
	Green->SetSelIndex(WorkingOptions->Green);
	Blue->ClearList();
	Blue->InsertString("Computer", -1);
	Blue->InsertString("Keyboard", -1);
	Blue->InsertString("Joystick", -1);
	Blue->SetSelIndex(WorkingOptions->Blue);
	Purple->ClearList();
	Purple->InsertString("Computer", -1);
	Purple->InsertString("Keyboard", -1);
	Purple->InsertString("Joystick", -1);
	Purple->SetSelIndex(WorkingOptions->Purple);
	Style->ClearList();
	Style->InsertString("Various", -1);
	Style->InsertString("Stone", -1);
	Style->InsertString("Radioactive", -1);
	Style->InsertString("Ice World", -1);
	Style->InsertString("Egyptian", -1);
	Style->SetSelIndex(WorkingOptions->Style);
	Order->ClearList();
	Order->InsertString("Random", -1);
	Order->InsertString("Sequence", -1);
	Order->InsertString("No Change", -1);
	Order->SetSelIndex(WorkingOptions->Order);
}

BOOL
TOptionsDialog::CanClose()
{
	TDialog::CanClose();
	Games->GetText(s, 4);
	WorkingOptions->Games=atoi(s);
	MazeNumber->GetText(s, 4);
	WorkingOptions->MazeNumber=atoi(s);
	MegaRiot->GetText(s, 4);
	WorkingOptions->MegaRiot=atoi(s);
	WorkingOptions->Red=Red->GetSelIndex();
	WorkingOptions->Green=Green->GetSelIndex();
	WorkingOptions->Blue=Blue->GetSelIndex();
	WorkingOptions->Purple=Purple->GetSelIndex();
	WorkingOptions->Style=Style->GetSelIndex();
	WorkingOptions->Order=Order->GetSelIndex();
	return TRUE;
}

TOptionsDialog::~TOptionsDialog()
{
	delete Red;
	delete Green;
	delete Blue;
	delete Purple;
	delete Style;
	delete Order;
	delete Games;
	delete MazeNumber;
	delete MegaRiot;
}

void
TOptionsDialog::IdcConfigureKeys()
{
	KeyBloke=0;
	KeyNumber=0;
	TGetKeyDialog* gk;
	gk=new TGetKeyDialog(this, KeyHolder);
	gk->Create();
	delete gk;
}

void
TOptionsDialog::EvKeyDown(uint Key, uint, uint f)
{
	if (KeyBloke!=-1 && (f&16384)==0) {
		  KeyHolder[KeyBloke*5+KeyNumber]=Key;
	}
}

DEFINE_RESPONSE_TABLE1(TOptionsDialog, TDialog)
#ifdef CONFIGURE
  EV_COMMAND(IDC_CONFIGURE, IdcConfigureKeys),
#endif
  EV_WM_KEYDOWN,
END_RESPONSE_TABLE;
