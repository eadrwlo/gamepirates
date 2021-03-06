//---------------------------------------------------------------------------

#ifndef mainMenuH
#define mainMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TmainMenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *startgame_button;
	TImage *options_button;
	TImage *endgame_button;
	void __fastcall endgame_buttonClick(TObject *Sender);
	void __fastcall options_buttonClick(TObject *Sender);
	void __fastcall startgame_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmainMenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TmainMenu_frame *mainMenu_frame;
//---------------------------------------------------------------------------
#endif
