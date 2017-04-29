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
#include <vector>
//---------------------------------------------------------------------------
class TstartgameMenu_frame : public TFrame
{
__published:	// IDE-managed Components
	TImage *numberOfPlayers_label;
	TImage *plus_button;
	TImage *minus_button;
	TImageList *listOfNumbers;
	TImage *startgame_button;
	TImage *goBack_button;
	TGlyph *number;
	Tplayer_frame *player_frame1;
	Tplayer_frame *player_frame2;
	Tplayer_frame *player_frame3;
	Tplayer_frame *player_frame4;
	void __fastcall startgame_buttonClick(TObject *Sender);
	void __fastcall goBack_buttonClick(TObject *Sender);
	void __fastcall plus_buttonClick(TObject *Sender);
	void __fastcall minus_buttonClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TstartgameMenu_frame(TComponent* Owner);
	vector <Tplayer_frame*> playerList;
	vector <Tplayer_frame*>::iterator it;
};
//---------------------------------------------------------------------------
extern PACKAGE TstartgameMenu_frame *startgameMenu_frame;
//---------------------------------------------------------------------------
#endif
