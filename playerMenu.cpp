//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "playerMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tplayer_frame *player_frame;
//---------------------------------------------------------------------------
__fastcall Tplayer_frame::Tplayer_frame(TComponent* Owner)
	: TFrame(Owner)
{

}
//---------------------------------------------------------------------------


void __fastcall Tplayer_frame::next_buttonClick(TObject *Sender)
{
	if (playerAvatar->ImageIndex < 5)
	{
		playerAvatar->ImageIndex++;

    }

}
//---------------------------------------------------------------------------

void __fastcall Tplayer_frame::previous_buttonClick(TObject *Sender)
{
	if (playerAvatar->ImageIndex >0)
	{
        playerAvatar->ImageIndex--;
    }

}
//---------------------------------------------------------------------------

void __fastcall Tplayer_frame::Text1Click(TObject *Sender)
{
	//Text1->
}
//---------------------------------------------------------------------------

