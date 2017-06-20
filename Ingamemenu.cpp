//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop
#include "ingameMenu.h"
#include "optionsMenu.h"
#include "frameMap.h"
#include "game.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TingameMenu_frame *ingameMenu_frame;
//---------------------------------------------------------------------------

__fastcall TingameMenu_frame::TingameMenu_frame(TComponent* Owner)
	: TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::options_buttonClick(TObject *Sender)
{
	ingameMenu_frame->Visible = false;
	optionsMenu_frame->Visible = true;
    inGameMenuBackground->Visible = true;
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::endgame_buttonClick(TObject *Sender)
{
    Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::goBackToGame_buttonClick(TObject *Sender)
{
	ingameMenu_frame->Visible = false;
    inGameMenuBackground->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TingameMenu_frame::goToMainMenu_buttonClick(TObject *Sender)
{
	mainMenu_frame->Visible = true;
	ingameMenu_frame->Visible = false;
	frame1Map->Visible = false;
	inGameMenuBackground->Visible = false;
	frame1Map->players.erase(frame1Map->players.begin(),frame1Map->players.end());
	frame1Map->playersWhoAreStillInGame.erase(frame1Map->playersWhoAreStillInGame.begin(),frame1Map->playersWhoAreStillInGame.end());
	vector<Field*>::iterator i;
	for (i=frame1Map->fieldsVector.begin();i<frame1Map->fieldsVector.end();i++)
	{
		if (dynamic_cast <Port*>(*i) != 0)
		{
			delete dynamic_cast <Port*>(*i)->cardFramePtr;
		}
		else if (dynamic_cast <PirateShip*>(*i) != 0)
		{
			delete dynamic_cast <PirateShip*>(*i)->cardFramePtr;
		}
		else if (dynamic_cast <Whirlpool*>(*i) != 0)
		{
			delete dynamic_cast <Whirlpool*>(*i)->cardFramePtr;
		}
		else if (dynamic_cast <LuckyWind*>(*i) != 0)
		{
			delete dynamic_cast <LuckyWind*>(*i)->cardFramePtr;
		}
		else if (dynamic_cast <Shallow*>(*i) != 0)
		{
			delete dynamic_cast <Shallow*>(*i)->cardFramePtr;
		}
		else if (dynamic_cast <Storm*>(*i) != 0)
		{
			delete dynamic_cast <Storm*>(*i)->cardFramePtr;
		}
	}
	frame1Map->fieldsVector.erase(frame1Map->fieldsVector.begin(),frame1Map->fieldsVector.end());
	frame1Map->playerStatisticsBoxFrame3->Visible = false;
	frame1Map->playerStatisticsBoxFrame4->Visible = false;
	frame1Map->playerStatisticsBoxFrame2->redFrame->Visible = false;
	frame1Map->playerStatisticsBoxFrame3->redFrame->Visible = false;
	frame1Map->playerStatisticsBoxFrame4->redFrame->Visible = false;
}
//---------------------------------------------------------------------------



