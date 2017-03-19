//---------------------------------------------------------------------------

#ifndef MainmenuH
#define MainmenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TMainmenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *Startgame_button;
	TImage *Options_button;
	TImage *Endgame_button;
	void __fastcall Endgame_buttonClick(TObject *Sender);
	void __fastcall Options_buttonClick(TObject *Sender);
	void __fastcall Startgame_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TMainmenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TMainmenu_frame *Mainmenu_frame;
//---------------------------------------------------------------------------
#endif
