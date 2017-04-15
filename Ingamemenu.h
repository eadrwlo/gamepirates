//---------------------------------------------------------------------------

#ifndef inGameMenuH
#define inGameMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
//---------------------------------------------------------------------------
class TIngamemenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *options_button;
	TImage *endgame_button;
	TImage *goBackToGame_button;
	TImage *goToMainMenu_button;
	void __fastcall options_buttonClick(TObject *Sender);
	void __fastcall endgame_buttonClick(TObject *Sender);
	void __fastcall goBackToGame_buttonClick(TObject *Sender);
	void __fastcall goToMainMenu_buttonClick(TObject *Sender);
	//void inGameMenuBackgroundVisibility(bool val);
private:	// User declarations
public:		// User declarations
	__fastcall TIngamemenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TIngamemenu_frame *Ingamemenu_frame;
extern TImage *inGameMenuBackground;
//---------------------------------------------------------------------------
#endif
