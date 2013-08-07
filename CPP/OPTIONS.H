#include <owl\edit.h>
#include <owl\dialog.h>
#include <owl\combobox.h>

#define COMPUTER 0
#define KEYBOARD 1
#define JOYSTICK 2

#define VARIOUS 0
#define STONE 1
#define DANGER 2
#define ICE 3
#define EGYPT 4

#define RANDOM 0
#define SEQUENCE 1
#define NOCHANGE 2

typedef struct {
  int Red, Green, Blue, Purple, Style, Order;
  int Games, MazeNumber, MegaRiot;
} OptionsStruct;

class TOptionsDialog : public TDialog
{
  public:
	  TOptionsDialog(TWindow*, OptionsStruct* Options, uint* Keys);
	  ~TOptionsDialog();
	  void SetupWindow();
	  BOOL CanClose();
	  void EvKeyDown(uint, uint, uint);
	  void IdcConfigureKeys();
   private:
	  char s[6];
	  uint* KeyHolder;
	  int KeyBloke, KeyNumber;
	  OptionsStruct* WorkingOptions;
	  TComboBox* Red;
	  TComboBox* Green;
	  TComboBox* Blue;
	  TComboBox* Purple;
	  TComboBox* Style;
	  TComboBox* Order;
	  TEdit *Games;
	  TEdit *MazeNumber;
	  TEdit *MegaRiot;
  DECLARE_RESPONSE_TABLE(TOptionsDialog);
};


