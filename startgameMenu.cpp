//---------------------------------------------------------------------------

#include <fmx.h>
#include "frameMap.h"
#pragma hdrstop

#include "startgameMenu.h"
#include "mainMenu.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "playerMenu"
#pragma resource "*.fmx"
TstartgameMenu_frame *startgameMenu_frame;
//---------------------------------------------------------------------------
__fastcall TstartgameMenu_frame::TstartgameMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
	number->ImageIndex = 0;
	player_frame3->Visible = false;
	player_frame4->Visible = false;
	playerList.push_back(player_frame3);
	playerList.push_back(player_frame4);
    it = playerList.begin();
}
//---------------------------------------------------------------------------


void __fastcall TstartgameMenu_frame::startgame_buttonClick(TObject *Sender)
{
	frame1Map->Visible = Visible;
	startgameMenu_frame->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TstartgameMenu_frame::goBack_buttonClick(TObject *Sender)
{
    startgameMenu_frame->Visible = false;
	mainMenu_frame->Visible = true;
}
//---------------------------------------------------------------------------


void __fastcall TstartgameMenu_frame::plus_buttonClick(TObject *Sender)
{
	if (number->ImageIndex < 2)
	{
		number->ImageIndex++;
		(*it)->Visible = true;
		it++;
	}
}
//---------------------------------------------------------------------------

void __fastcall TstartgameMenu_frame::minus_buttonClick(TObject *Sender)
{
	if (number->ImageIndex > 0)
	{
		number->ImageIndex--;
        it--;
		(*it)->Visible = false;

	}
}
//---------------------------------------------------------------------------

