//---------------------------------------------------------------------------

#include <fmx.h>
#pragma hdrstop

#include "commonCard.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.fmx"
TcommonCardFrame *commonCardFrame;
//---------------------------------------------------------------------------
__fastcall TcommonCardFrame::TcommonCardFrame(TComponent* Owner)
	: TFrame(Owner)
{
    this->Parent = static_cast<TFrame*>(Owner);
	this->Visible = false;
	this->Position->X = 750;
	this->Position->Y = 220;
}
//---------------------------------------------------------------------------
void __fastcall TcommonCardFrame::payButtonClick(TObject *Sender)
{

	Visible = false;
}
//---------------------------------------------------------------------------
