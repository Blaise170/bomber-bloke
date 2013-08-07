#include <owl\static.h>
#include <owl\dialog.h>

class TGetKeyDialog : public TWindow
{
  public:
	  TGetKeyDialog(TWindow*, uint*);
	  ~TGetKeyDialog();
	  void SetupWindow();
	  BOOL CanClose();
	  void EvKeyDown(uint, uint, uint);
	private:
     char s[100];
     int Key, Bloke;
     uint* KeyHolder;
	  char* WorkingKey;
	  char* StaticText;
	DECLARE_RESPONSE_TABLE(TGetKeyDialog);
};


