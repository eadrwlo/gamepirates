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
	this->Position->X = 800;
	this->Position->Y = 280;
}
//---------------------------------------------------------------------------
void __fastcall TpirateShipFrame::closeButtonClick(TObject *Sender)
{
	Visible = false;
}
//---------------------------------------------------------------------------
