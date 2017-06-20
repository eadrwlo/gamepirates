//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "whirlpoolCard.h"
#include "frameMap.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TwhirlpoolCardFrame *whirlpoolCardFrame;
//---------------------------------------------------------------------------
__fastcall TwhirlpoolCardFrame::TwhirlpoolCardFrame(TComponent* Owner)
	: TFrame(Owner)
{
	this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 800;
	this->Position->Y = 280;
}

TGlyph *TwhirlpoolCardFrame::getNumber1()
{
    return number1;
}
//---------------------------------------------------------------------------
void __fastcall TwhirlpoolCardFrame::ZamknijClick(TObject *Sender)
{
    Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TwhirlpoolCardFrame::closeButtonClick(TObject *Sender)
{
    frame1Map->players[(frame1Map->indexOfPlayer) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=false;
	frame1Map->players[(frame1Map->indexOfPlayer+1) % frame1Map->numberOfPlayers]->playerStatisticsBoxFramePtr->redFrame->Visible=true;
	Visible = false;
}
//---------------------------------------------------------------------------

