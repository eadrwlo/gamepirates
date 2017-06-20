//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "pirateShipCard.h"
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
//TpirateShipCardFrame *pirateShipCardFrame;
//---------------------------------------------------------------------------
__fastcall TpirateShipCardFrame::TpirateShipCardFrame(TComponent* Owner, int cardNumber)
	: TFrame(Owner)
{
	UnicodeString newName = this->Name;
	newName = newName.operator +=(UnicodeString(cardNumber));
    this->Name = newName;
	this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TpirateShipCardFrame::closeButtonClick(TObject *Sender)
{
    frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
	frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
	Visible = false;
	badPirate->Visible = true;
	goodPirate->Visible = true;
	amountOfBonusLabel->Visible = true;
}
//---------------------------------------------------------------------------
