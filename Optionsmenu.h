//---------------------------------------------------------------------------

#ifndef optionsMenuH
#define optionsMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Objects.hpp>
#include <FMX.Types.hpp>
#include "Mainmenu.h"
//---------------------------------------------------------------------------
class TOptions_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *gameInWinow_label;
	TImage *music_label;
	TImage *goBack_button;
	TImage *settings_label;
	TImage *checkOFF_gameInWindow;
	TImage *checkOFF_music;
	TImage *checkON_gameInWindow;
	TImage *checkON_music;
	TImage *volumeBar_label;
	TImage *volumeButton_button;
	void __fastcall goBack_buttonClick(TObject *Sender);
	void __fastcall checkON_gameInWindowClick(TObject *Sender);
	void __fastcall checkOFF_gameInWindowClick(TObject *Sender);
	void __fastcall checkOFF_musicClick(TObject *Sender);
	void __fastcall checkON_musicClick(TObject *Sender);
	void __fastcall volumeButton_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TOptions_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TOptions_frame *Options_frame;
//---------------------------------------------------------------------------
#endif
