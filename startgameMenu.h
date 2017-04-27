//---------------------------------------------------------------------------

#ifndef startgameMenuH
#define startgameMenuH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <FMX.Controls.hpp>
#include <FMX.Forms.hpp>
#include <FMX.Controls.Presentation.hpp>
#include <FMX.Objects.hpp>
#include <FMX.StdCtrls.hpp>
#include <FMX.Types.hpp>
#include "playerMenu.h"
#include <FMX.ImgList.hpp>
#include <System.ImageList.hpp>
//---------------------------------------------------------------------------
class TstartgameMenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *numberOfPlayers_label;
	TImage *plus_button;
	TImage *minus_button;
	Tplayer_frame *Frame11;
	Tplayer_frame *Frame12;
	Tplayer_frame *player_frame1;
	Tplayer_frame *player_frame2;
	TImageList *listOfNumbers;
	TImage *startgame_button;
	TImage *goBack_button;
	TGlyph *number;
	void __fastcall startgame_buttonClick(TObject *Sender);
	void __fastcall goBack_buttonClick(TObject *Sender);
	void __fastcall plus_buttonClick(TObject *Sender);
	void __fastcall minus_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TstartgameMenu_frame(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TstartgameMenu_frame *startgameMenu_frame;
//---------------------------------------------------------------------------
#endif
