//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "pirateShipCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TpirateShipFrame *pirateShipFrame;
//---------------------------------------------------------------------------
__fastcall TpirateShipFrame::TpirateShipFrame(TComponent* Owner)
	: TFrame(Owner)
{
	this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TpirateShipFrame::closeButtonClick(TObject *Sender)
{
	Visible = false;
	badPirate->Visible = true;
    goodPirate->Visible = true;
}
//---------------------------------------------------------------------------
