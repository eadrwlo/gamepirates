//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "playerMenu.h"
#include "startgameMenu.h"
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
Tplayer_frame *player_frame;
//---------------------------------------------------------------------------
__fastcall Tplayer_frame::Tplayer_frame(TComponent* Owner)
	: TFrame(Owner)
{

   //	 frame1Map->player1->Bitmap = playerPictruesList->Source[0];

}
//---------------------------------------------------------------------------


void __fastcall Tplayer_frame::next_buttonClick(TObject *Sender)
{
    int k=0;
	if (playerAvatar->ImageIndex < 6  )
	{

		for (int i=1;i<6;i++)
		{
			for (int j=0;j<startgameMenu_frame->number->ImageIndex + 2;j++)
			{
				if(playerAvatar->ImageIndex + i !=startgameMenu_frame->playerList[j]->playerAvatar->ImageIndex)
				{
					k++;
				}
			}
			if(playerAvatar->ImageIndex + i >= 6)
			{
				return;
			}
			if (k==startgameMenu_frame->number->ImageIndex + 2)
			{
				playerAvatar->ImageIndex =playerAvatar->ImageIndex+i;
				return;
			}
			k=0;
		}
    }

}
//---------------------------------------------------------------------------

void __fastcall Tplayer_frame::previous_buttonClick(TObject *Sender)
{
	int k=0;
	if (playerAvatar->ImageIndex >0)
	{
		for (int i=1;i<6;i++)
		{
			for (int j=0;j<startgameMenu_frame->number->ImageIndex + 2;j++)
			{
				if(playerAvatar->ImageIndex - i !=startgameMenu_frame->playerList[j]->playerAvatar->ImageIndex)
				{
					k++;
				}
			}
            if(playerAvatar->ImageIndex - i < 0)
			{
				return;
			}
			if (k==startgameMenu_frame->number->ImageIndex + 2)
			{
				playerAvatar->ImageIndex = playerAvatar->ImageIndex-i;

                return;
			}
			k=0;
		}
    }

}
//---------------------------------------------------------------------------



void __fastcall Tplayer_frame::playerNameInputClick(TObject *Sender)
{
	this->playerNameInput->Text = "";
}
//---------------------------------------------------------------------------


