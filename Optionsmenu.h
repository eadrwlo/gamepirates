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
class ToptionsMenu_frame : public TFrame
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
	TTimer *volumeButton_timer;
	TImage *volume_label;
	void __fastcall goBack_buttonClick(TObject *Sender);
	void __fastcall checkON_gameInWindowClick(TObject *Sender);
	void __fastcall checkOFF_gameInWindowClick(TObject *Sender);
	void __fastcall checkOFF_musicClick(TObject *Sender);
	void __fastcall checkON_musicClick(TObject *Sender);
	void __fastcall volumeButton_buttonMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, float X, float Y);
	void __fastcall volumeButton_timerTimer(TObject *Sender);
	void __fastcall volumeButton_buttonMouseUp(TObject *Sender, TMouseButton Button,
		  TShiftState Shift, float X, float Y);
private:	// User declarations
public:		// User declarations
	__fastcall ToptionsMenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE ToptionsMenu_frame *optionsMenu_frame;
//---------------------------------------------------------------------------
#endif
